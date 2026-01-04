

struct SnowF
{
    ImVec2 Pos;
    float snowSpeed, snowMotion, Size;
    ImU32 Color;
};

void Snowflakes()
{
    static std::vector<SnowF> Snow(100);
    static std::vector<SnowF> Snow1(100);
    static bool Init = false;
    auto Screen = ImGui::GetIO().DisplaySize;

    if (!Init)
    {
        for (auto& S : Snow)
        {
            S.Pos = ImVec2(rand() % (int)Screen.x, rand() % (int)Screen.y);
            S.snowSpeed = 2.0f + (rand() % 100) / 100.0f;
            S.snowMotion = 1.5f + (rand() % 100) / 200.0f;
            S.Size = 1.5f + rand() % 2;
            S.Color = IM_COL32(255, 255, 255, 100);
        }

        for (auto& S : Snow1)
        {
            S.Pos = ImVec2(rand() % (int)Screen.x, rand() % (int)Screen.y);
            S.snowSpeed = 1.6f + (rand() % 100) / 100.0f;
            S.snowMotion = 1.f + (rand() % 100) / 200.0f;
            S.Size = 1.5f + rand() % 2;
            S.Color = IM_COL32(255, 255, 255, 255);
        }
        Init = true;
    }

    static float time = 0.0f;
    time += ImGui::GetIO().DeltaTime;

    for (auto& S : Snow)
    {
        S.Pos.y += S.snowSpeed;
        S.Pos.x += sin(time * S.snowMotion) * 0.5f;
        if (S.Pos.y > Screen.y)
        {
            S.Pos.y = 0;
            S.Pos.x = rand() % (int)Screen.x;
        }
        ImGui::GetBackgroundDrawList()->AddCircleFilled(S.Pos, S.Size, S.Color);
    }

    for (auto& S : Snow1)
    {
        S.Pos.y += S.snowSpeed;
        S.Pos.x += sin(time * S.snowMotion) * 1.f;
        if (S.Pos.y > Screen.y)
        {
            S.Pos.y = 0;
            S.Pos.x = rand() % (int)Screen.x;
        }
        ImGui::GetForegroundDrawList()->AddCircleFilled(S.Pos, S.Size, S.Color);
    }
}


struct Notification {
    std::string title;
    std::string message;
    float duration;
    float currentTime;
    float animationProgress;
    bool isActive;

    Notification(const std::string& t, const std::string& m, float d)
        : title(t), message(m), duration(d), currentTime(0.0f), animationProgress(0.0f), isActive(true) {
    }
};

std::vector<Notification> m_notifications;
float m_notificationWidth = 260.0f;
float m_notificationHeight = 50.0f;
float m_notificationPadding = 12.0f;
float m_notificationSpacing = 10.0f;
float m_notificationAnimationSpeed = 3.0f;

void AddNotification(const std::string& title, const std::string& message, float duration = 20.0f) {
    m_notifications.emplace_back(title, message, duration);
}

void RenderNotifications() {
    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    ImDrawList* drawList = ImGui::GetBackgroundDrawList();
    float deltaTime = ImGui::GetIO().DeltaTime;

    float currentY = 20.0f;

    for (auto it = m_notifications.begin(); it != m_notifications.end();) {
        auto& notification = *it;

        notification.currentTime += deltaTime;

        float targetProgress = (notification.currentTime < notification.duration) ? 1.0f : 0.0f;
        notification.animationProgress += (targetProgress - notification.animationProgress) *
            (std::min)(1.0f, deltaTime * m_notificationAnimationSpeed);

        if (notification.animationProgress < 0.01f && notification.currentTime >= notification.duration) {
            it = m_notifications.erase(it);
            continue;
        }

        float slideOffset = (1.0f - notification.animationProgress) * m_notificationWidth;
        float alpha = notification.animationProgress;
        float x = displaySize.x - m_notificationWidth - 20.0f + slideOffset;
        float y = currentY;

        drawList->AddRectFilled(
            ImVec2(x + 4, y + 4),
            ImVec2(x + m_notificationWidth + 4, y + m_notificationHeight + 4),
            IM_COL32(0, 0, 0, int(120 * alpha)),
            8.0f
        );

        drawList->AddRectFilled(
            ImVec2(x + 2, y + 2),
            ImVec2(x + m_notificationWidth - 2, y + m_notificationHeight - 2),
            IM_COL32(12, 12, 12, int(255 * alpha)),
            8.0f
        );

        drawList->AddRectFilled(
            ImVec2(x, y),
            ImVec2(x + m_notificationWidth, y + m_notificationHeight),
            IM_COL32(15, 15, 15, int(255 * alpha)),
            8.0f
        );
        ImFont* textFont = ImGui::GetFont();
        std::string combinedText = notification.title + ": " + notification.message;
        ImVec2 textSize = textFont->CalcTextSizeA(textFont->FontSize * 0.9f, FLT_MAX, 0.0f, combinedText.c_str());
        float textX = x + (m_notificationWidth - textSize.x) / 2;
        float textY = y + (m_notificationHeight - textSize.y) / 2 - 5.0f;
        std::string titlePart = notification.title + ": ";
        ImVec2 titleSize = textFont->CalcTextSizeA(textFont->FontSize * 0.9f, FLT_MAX, 0.0f, titlePart.c_str());

        drawList->AddText(
            textFont,
            textFont->FontSize * 0.9f,
            ImVec2(textX, textY),
            IM_COL32(255, 255, 255, int(255 * alpha)),
            titlePart.c_str()
        );

        drawList->AddText(
            textFont,
            textFont->FontSize * 0.9f,
            ImVec2(textX + titleSize.x, textY),
            IM_COL32(200, 200, 200, int(255 * alpha)),
            notification.message.c_str()
        );

        float progressBarHeight = 2.0f;
        float progressBarWidth = m_notificationWidth - (m_notificationPadding * 2);
        float progressBarX = x + m_notificationPadding;
        float progressBarY = y + m_notificationHeight - m_notificationPadding - progressBarHeight;

        drawList->AddRectFilled(
            ImVec2(progressBarX, progressBarY),
            ImVec2(progressBarX + progressBarWidth, progressBarY + progressBarHeight),
            IM_COL32(50, 50, 50, int(180 * alpha)),
            1.0f
        );

        float progress = notification.currentTime / notification.duration;
        progress = (std::min)(1.0f, progress);

        drawList->AddRectFilled(
            ImVec2(progressBarX, progressBarY),
            ImVec2(progressBarX + (progressBarWidth * (1.0f - progress)), progressBarY + progressBarHeight),
            IM_COL32(90, 140, 230, int(255 * alpha)),
            1.0f
        );


        currentY += m_notificationHeight + m_notificationSpacing;

        ++it;
    }
}
