
void DrawMovementSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 15, 80));
    ImGui::BeginChild("st4rmovementt", ImVec2(260, 190), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Movement");

    ImGui::SetCursorPos(ImVec2(10, 45));
    ImGui::BeginGroup();
    ImGui::CustomCheckbox("Button 1", &globals::btn);
    ImGui::CustomCheckbox("Button 2", &globals::btn2);

    ImGui::CustomCheckbox("Button 3", &globals::btn3);
    if (globals::btn3)
    {
        ImGui::SliderFloat2("##WalkVal", &globals::one, 0.0f, 100.0f, "%.0f");
    }

    ImGui::CustomCheckbox("Button 4", &globals::btn5);
    if (globals::btn5)
    {
        ImGui::SliderFloat2("##JumpVal", &globals::two, 0.0f, 100.0f, "%.0f");
    }

    ImGui::CustomCheckbox("Button 5", &globals::btn7);

    ImGui::EndGroup();
    ImGui::EndChild();
}

void DrawVisualsSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 285, 80));
    ImGui::BeginChild("st4rrvisuals", ImVec2(260, 185), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Visuals");

    ImGui::SetCursorPos(ImVec2(10, 45));
    ImGui::BeginGroup();
    ImGui::CustomCheckbox("Button 6", &globals::btn8);

    if (globals::btn8) ImGui::SliderFloat2("modifier", &globals::three, 10.0f, 120.0f, "%.0f");

    ImGui::CustomCheckbox("Button 7", &globals::btn9);
    if (globals::btn9) {
        ImGui::CustomCheckbox("Button 8", &globals::btn10);
        ImGui::CustomCheckbox("Button 9", &globals::btn11);
        if (globals::btn11) {
            ImGui::CustomCheckbox("Button 10", &globals::btn12);
        }
    }

    ImGui::CustomCheckbox("Button 11", &globals::btn13);
    if (globals::btn13)
    {
        ImGui::CustomCheckbox("Button 12", &globals::btn14);
        ImGui::CustomCheckbox("Button 13", &globals::btn15);
        ImGui::CustomCheckbox("Button 14", &globals::btn16);
        if (globals::btn16)
        {
            ImGui::CustomCheckbox("Button 15", &globals::btn17);
        }
        ImGui::CustomCheckbox("Button 16", &globals::btn18);
        if (globals::btn18) ImGui::CustomCheckbox("Button 17", &globals::btn19);

        ImGui::PushItemWidth(100);
        ImGui::InputFloat("##Opacity", &globals::four, 0, 0, "%.1f");
        ImGui::PopItemWidth();
        ImGui::SetItemTooltip("Configure opacity");
    }
    ImGui::EndGroup();
    ImGui::EndChild();
}

void DrawVisualSettingsSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 285, 285));
    ImGui::BeginChild("st4rrvisualsets", ImVec2(260, 110), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Visual Settings");

    ImGui::SetCursorPos(ImVec2(10, 50));
    auto vsPos = ImGui::GetCursorScreenPos();
    draw->AddText(Fonts::ArrowFont, 15.0f, vsPos, ImColor(150, 150, 150), "Color 1");
    ImGui::Dummy(ImVec2(80, 20));
    ImGui::SameLine(200);
    ImGui::SetCursorPosY(47);
    ImGui::ColorEdit3("##TracerColor", (float*)&globals::col1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha);

    ImGui::SetCursorPos(ImVec2(10, 75));
    vsPos = ImGui::GetCursorScreenPos();
    draw->AddText(Fonts::ArrowFont, 15.0f, vsPos, ImColor(150, 150, 150), "Color 2");
    ImGui::Dummy(ImVec2(80, 20));
    ImGui::SameLine(200);
    ImGui::SetCursorPosY(72);
    ImGui::ColorEdit3("##NameColor", (float*)&globals::col2, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoAlpha);

    ImGui::EndChild();
}

void DrawCombatSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 15, 285));
    ImGui::BeginChild("st4rr", ImVec2(260, 205), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Combat");

    ImGui::SetCursorPos(ImVec2(10, 45));
    ImGui::BeginGroup();
    ImGui::CustomCheckbox("Button 18", &globals::btn20);
    ImGui::CustomCheckbox("Button 19", &globals::btn21);
    ImGui::CustomCheckbox("Button 20", &globals::btn22);
    if (globals::btn22)
    {
        ImGui::CustomCheckbox("Button 21", &globals::btn23);
        if (globals::btn23)
        {
            ImGui::CustomCheckbox("Button 22", &globals::btn24);
            ImGui::CustomCheckbox("Button 23", &globals::btn25);
            ImGui::CustomCheckbox("Button 24", &globals::btn26);
        }
        ImGui::CustomCheckbox("Button 25", &globals::btn27);
        ImGui::CustomCheckbox("Button 26", &globals::btn28);
        if (globals::btn28)
        {
            ImGui::PushItemWidth(100);
            ImGui::InputFloat("##BSpeed", &globals::five, 0, 0, "%.1f");
            ImGui::PopItemWidth();
        }
        ImGui::CustomCheckbox("Button 27", &globals::btn29);
        if (globals::btn29)
        {
            ImGui::PushItemWidth(100);
            ImGui::InputInt("##BCount", &globals::num, 0, 0);
            ImGui::PopItemWidth();
        }
    }
    ImGui::EndGroup();
    ImGui::EndChild();
}

void DrawAntiSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 15, 80));
    ImGui::BeginChild("st4rrrr", ImVec2(260, 200), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Anti Features");

    ImGui::SetCursorPos(ImVec2(10, 45));
    ImGui::BeginGroup();
    ImGui::CustomCheckbox("Option 1", &globals::option::opt1);
    ImGui::CustomCheckbox("Option 2", &globals::option::opt2);
    ImGui::CustomCheckbox("Option 3", &globals::option::opt3);
    ImGui::CustomCheckbox("Option 4", &globals::option::opt4);
    ImGui::CustomCheckbox("Option 5", &globals::option::opt5);
    ImGui::EndGroup();
    ImGui::EndChild();
}

void DrawFlingSection(float sidebarWidth)
{
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 285, 80));
    ImGui::BeginChild("st4rrrrr", ImVec2(260, 200), true);
    auto draw = ImGui::GetWindowDrawList();
    auto pos = ImGui::GetWindowPos();
    auto size = ImGui::GetWindowSize();
    ImGui::DrawHeaderGradient(draw, pos, size, 35, "Configurables");

    ImGui::SetCursorPos(ImVec2(10, 45));
    ImGui::BeginGroup();
    ImGui::CustomCheckbox("Button 28", &globals::btn30);
    ImGui::EndGroup();
    ImGui::EndChild();
}

void MainTab()
{
    ImGui::PushFont(Fonts::ArrowFont);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.08f, 0.08f, 0.09f, 0.8f));
    ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.15f, 0.15f, 0.17f, 0.9f));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 6.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
    float sidebarWidth = 180 * 1.1f;

    static int activeTab = 0;
    ImGui::SetCursorPos(ImVec2(sidebarWidth + 15, 25));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.15f, 0.15f, 0.17f, 0.5f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.2f, 0.2f, 0.22f, 0.8f));

    const char* tabs[] = { "Main", "Null", "Tab 2" };
    for (int i = 0; i < 3; i++)
    {
        if (i > 0) ImGui::SameLine(0, 15);
        ImGui::PushStyleColor(ImGuiCol_Text, activeTab == i ? ImVec4(1, 1, 1, 1) : ImVec4(0.6f, 0.6f, 0.65f, 1));
        ImGui::PushID(100 + i);
        if (ImGui::Button(tabs[i], ImVec2(80, 25))) activeTab = i;
        ImGui::PopID();
        ImGui::PopStyleColor();
    }
    ImGui::PopStyleColor(3);

    if (activeTab == 0)
    {
        DrawMovementSection(sidebarWidth);
        DrawVisualsSection(sidebarWidth);
        DrawVisualSettingsSection(sidebarWidth);
        DrawCombatSection(sidebarWidth);
    }
    else if (activeTab == 2)
    {
        DrawAntiSection(sidebarWidth);
        DrawFlingSection(sidebarWidth);
    }

    ImGui::PopStyleVar(2);
    ImGui::PopStyleColor(2);
    ImGui::PopFont();
}