void DrawSettingsSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 15, 80));
    ImGui::BeginChild("st4rrrrrr", ImVec2(260, 220), true, ImGuiWindowFlags_AlwaysUseWindowPadding);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 30, "Settings");
    draw->AddLine(ImVec2(pos.x + 10, pos.y + 30), ImVec2(pos.x + size.x - 10, pos.y + 30), ImColor(0.15f, 0.15f, 0.17f, 0.9f), 1.0f);

    ImGui::SetCursorPos(ImVec2(15, 8));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.7f, 0.7f, 0.75f, 1.0f));
    ImGui::Text("Settings");
    ImGui::PopStyleColor();

    ImGui::SetCursorPos(ImVec2(15, 40));
    ImGui::BeginGroup();

    ImGui::CustomCheckbox("Snowflakeys", &globals::snowflakeys);
    ImGui::CustomCheckbox("Dim", &globals::dimmenu);
    if (globals::dimmenu) {
        ImGui::SliderFloat2("##DimAmount", &globals::dimAmount, 0.0f, 1.0f, "%.0f");
    }

    ImGui::EndGroup();
    ImGui::EndChild();
}

void SettingsTab()
{
    float sidebarWidth = 180 * 1.1f;

    ImGui::PushFont(Fonts::ArrowFont);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.08f, 0.09f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.15f, 0.15f, 0.17f, 0.9f));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.55f, 0.55f, 0.6f, 1.0f));

    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.5f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 10));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 8));

    DrawSettingsSection(sidebarWidth);

    ImGui::PopStyleVar(4);
    ImGui::PopStyleColor(3);
    ImGui::PopFont();
}
