#pragma once


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */


enum Heads { main, misc, visuals, exploits, playerlist, assetspawn, config, settings };

namespace Menu {
    static Heads Tab = main;
}


float Clamp(float val, float min, float max) {
    return val < min ? min : (val > max ? max : val);
}


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */



void InitFonts() {
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;


    ImFontConfig font_config;
    font_config.PixelSnapH = false;
    font_config.OversampleH = 8;
    font_config.OversampleV = 8;
    font_config.RasterizerMultiply = 1.2f;

    static const ImWchar ranges[] = { 0x0020, 0x00FF, 0x0400, 0x052F, 0x2DE0, 0x2DFF, 0xA640, 0xA69F, 0xE000, 0xE226, 0 };

    font_config.GlyphRanges = ranges;


    Fonts::Medium = io.Fonts->AddFontFromMemoryTTF(StolzlFont, sizeof(StolzlFont), 15.0f, &font_config, ranges);


    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    ImFontConfig icons_config;
    icons_config.MergeMode = true;
    icons_config.PixelSnapH = true;
    icons_config.OversampleH = 8;
    icons_config.OversampleV = 8;
    Fonts::FontAwesome = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 16.0f, &icons_config, icons_ranges);


    Fonts::Large = io.Fonts->AddFontFromMemoryTTF(StolzlFont, sizeof(StolzlFont), 23.0f, &font_config, ranges);
    Fonts::Bold = io.Fonts->AddFontFromMemoryTTF(StolzlBold, sizeof(StolzlBold), 17.0f, &font_config, ranges);
    Fonts::ArrowFont = io.Fonts->AddFontFromMemoryTTF(ArrowFont, sizeof(ArrowFont), 15.0f, &font_config, ranges);


    ImGui::StyleColorsDark();
    ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.07f, 0.95f);
    ImGui::GetStyle().Colors[ImGuiCol_ChildBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.10f, 0.11f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.15f, 0.17f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ImVec4(0.18f, 0.18f, 0.20f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.11f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.13f, 0.13f, 0.15f, 1.0f);
    ImGui::GetStyle().Colors[ImGuiCol_Text] = ImVec4(0.85f, 0.85f, 0.9f, 1.0f);
}


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */


void St4rfall() {

    ImGui::SetNextWindowSize(ImVec2(760, 550), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->GetCenter(), ImGuiCond_Once, ImVec2(0.5f, 0.5f));


    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);

    float sidebarWidth = 180 * 1.1f;


    ImGui::Begin("##starshine", nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize);
    {

        auto draw = ImGui::GetWindowDrawList();
        auto pos = ImGui::GetWindowPos();
        auto size = ImGui::GetWindowSize();

        static bool isuserdragging = false;
        static ImVec2 touch;

        ImVec2 mousePos = ImGui::GetMousePos();
        bool isHoveringWindow = ImGui::IsWindowHovered(ImGuiHoveredFlags_ChildWindows | ImGuiHoveredFlags_AllowWhenBlockedByActiveItem);

        if (ImGui::IsMouseClicked(0) && isHoveringWindow && !ImGui::IsAnyItemActive() && !ImGui::IsAnyItemHovered()) {
            isuserdragging = true;
            touch = ImVec2(mousePos.x - pos.x, mousePos.y - pos.y);
        }

        if (isuserdragging) {
            if (ImGui::IsMouseDown(0)) {
                ImVec2 newposition = ImVec2(mousePos.x - touch.x, mousePos.y - touch.y);
                ImGui::SetWindowPos(newposition);
            }
            else {
                isuserdragging = false;
            }
        }

        if (globals::dimmenu) {
            if (globals::dimAlpha > 0.0f) {
                ImGui::GetBackgroundDrawList()->AddRectFilled(
                    ImVec2(-1000, -1000),
                    ImVec2(size.x + 5000, 5000),
                    ImColor(0.0f, 0.0f, 0.0f, globals::dimAlpha * 0.8f)
                );
            }
        }


        static float time = 0.0f;
        time += ImGui::GetIO().DeltaTime * 0.8f;


        for (int i = 0; i < 45; i++) {
            float d = (float)i * 0.22f, breath = sin(time * 1.5f + i * 0.05f) * 1.8f, wave = cos(time * 1.2f - i * 0.08f) * 1.3f, fade = (1.0f - (float)i / 45), var = sin(i * 2.3f) * 0.4f + 0.6f, alpha = 0.04f * fade * var;
            ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(pos.x - d + breath, pos.y - d + wave), ImVec2(pos.x + 760 + d - breath, pos.y + 550 + d - wave), ImColor(0.565f, 0.612f, 1.0f, alpha), 25.0f + i * 0.3f );
        }


        draw->AddRectFilled(pos, ImVec2(pos.x + 760, pos.y + 550), ImColor(0.06f, 0.06f, 0.07f, 0.95f), 25.0f, ImDrawFlags_RoundCornersAll);


        draw->AddRect(pos, ImVec2(pos.x + 760, pos.y + 550), ImColor(0.15f, 0.15f, 0.17f, 0.5f), 25.0f, ImDrawFlags_RoundCornersAll, 0.5f);


        draw->AddLine(ImVec2(pos.x + sidebarWidth, pos.y + 15), ImVec2(pos.x + sidebarWidth, pos.y + 550 - 15), ImColor(0.15f, 0.15f, 0.17f, 0.9f), 1.0f);


        const char* titleLean = "star";
        const char* titleCat = "fall";
        ImVec2 leanSize = ImGui::CalcTextSize(titleLean);
        ImVec2 catSize = ImGui::CalcTextSize(titleCat);

        float spacing = 14.0f;
        float totalWidth = leanSize.x + catSize.x + spacing;
        float titleX = pos.x + (sidebarWidth - totalWidth) * 0.5f;

        draw->AddText(Fonts::Large, 22.0f, ImVec2(titleX, pos.y + 42), ImColor(143, 151, 255, 255), titleLean);

        draw->AddText(Fonts::Large, 22.0f, ImVec2(titleX + leanSize.x + spacing, pos.y + 42), ImColor(255, 255, 255, 255), titleCat);


        float sepWidth = sidebarWidth * 0.7f;
        float sepX = pos.x + (sidebarWidth - sepWidth) * 0.5f;

        draw->AddLine(ImVec2(sepX, pos.y + 75), ImVec2(sepX + sepWidth, pos.y + 75), ImColor(0.15f, 0.15f, 0.17f, 0.9f), 1.0f);


        ImGui::SetCursorPos({ 25, 95 });
        ImGui::BeginGroup();
        {

            ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0, 0, 0, 0));
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.85f, 0.85f, 0.9f, 1.0f));


            if (ImGui::Tab(Menu::Tab == main, ICON_FA_THUMBTACK, "Main", ImVec2(sidebarWidth - 50, 30)))
                Menu::Tab = main;

            if (ImGui::Tab(Menu::Tab == settings, ICON_FA_TOOLBOX, "Settings", ImVec2(sidebarWidth - 50, 30)))
                Menu::Tab = settings;

            ImGui::PopStyleColor(4);

        }
        ImGui::EndGroup();


        switch (Menu::Tab)
        {
        case main:
            MainTab();
            break;

        case settings:
            SettingsTab();
            break;
        }

    }
    ImGui::End();


    ImGui::PopStyleVar(2);

}


/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_KEYDOWN && wParam == VK_INSERT) {
        globals::show = !globals::show;
        if (globals::show) {
            GetCursorPos(&globals::originalCursorPos);
            ClipCursor(NULL);
            ImGui::GetIO().MouseDrawCursor = true;
        }
        else {
            ImGui::GetIO().MouseDrawCursor = false;
            SetCursorPos(globals::originalCursorPos.x, globals::originalCursorPos.y);
        }
        return 1;
    }

    if (globals::show) {
        ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
        if ((msg >= WM_MOUSEFIRST && msg <= WM_MOUSELAST) ||
            (msg >= WM_KEYFIRST && msg <= WM_KEYLAST) ||
            msg == WM_INPUT)
            return 1;
    }

    return CallWindowProc(globals::oWndProc, hwnd, msg, wParam, lParam);
}


HRESULT __stdcall hkp(IDXGISwapChain* sc, UINT sync, UINT flags)
{
    if (!globals::init)
    {
        if (SUCCEEDED(sc->GetDevice(__uuidof(ID3D11Device), (void**)&globals::dev)))
        {
            globals::dev->GetImmediateContext(&globals::ctx);
            globals::window = FindWindowA("UnityWndClass", nullptr);

            ID3D11Texture2D* buf;
            sc->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buf);
            if (buf)
            {
                globals::dev->CreateRenderTargetView(buf, nullptr, &globals::rtv);
                buf->Release();

                ImGui::CreateContext();
                ImGui_ImplWin32_Init(globals::window);
                ImGui_ImplDX11_Init(globals::dev, globals::ctx);
                InitFonts();

                globals::oWndProc = (WNDPROC)SetWindowLongPtr(globals::window, GWLP_WNDPROC, (LONG_PTR)WndProc);
                globals::init = true;
            }
        }
        else
            return globals::oPresent(sc, sync, flags);
    }

    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    float deltaTime = ImGui::GetIO().DeltaTime;
    float openSpeed = 14.0f * deltaTime;
    float closeSpeed = 9999.0f * deltaTime;

    if (globals::show) {
        globals::dimAlpha = Clamp(globals::dimAlpha + openSpeed, 0.0f, globals::dimAmount);
        globals::menuAlpha = Clamp(globals::menuAlpha + openSpeed, 0.0f, 1.0f);
    }
    else {
        globals::dimAlpha = Clamp(globals::dimAlpha - closeSpeed, 0.0f, globals::dimAmount);
        globals::menuAlpha = Clamp(globals::menuAlpha - closeSpeed, 0.0f, 1.0f);
    }

    RenderNotifications();

    if (globals::menuAlpha > 0.0f) {

        if (globals::snowflakeys) {
            Snowflakes();
        }

        St4rfall();
    }

    ImGui::Render();
    globals::ctx->OMSetRenderTargets(1, &globals::rtv, nullptr);
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    return globals::oPresent(sc, sync, flags);
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
