#pragma once
namespace globals {

    bool snowflakeys, dimmenu;
    float dimAmount = 1.0f, dimAlpha = 0.0f, menuAlpha = 0.0f;

    bool btn, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, btn11, btn12, btn13, btn14, btn15, btn16, btn17, btn18, btn19, btn20, btn21, btn22, btn23, btn24, btn25, btn26, btn27, btn28, btn29, btn30;
    float one, two, three, four, five;

    int num;

    ImVec4 col1, col2;

    namespace option
    {
        bool opt1, opt2, opt3, opt4, opt5;
    }

    typedef HRESULT(__stdcall* Present)(IDXGISwapChain*, UINT, UINT);
    Present oPresent;
    ID3D11Device* dev;
    ID3D11DeviceContext* ctx;
    ID3D11RenderTargetView* rtv;
    HWND window;
    POINT originalCursorPos;
    WNDPROC oWndProc;
    bool init, show;
}


namespace InHelper {
    bool InputText(const char* label, std::string* str) {
        static char buffer[256];
        strcpy_s(buffer, sizeof(buffer), str->c_str());
        bool changed = ImGui::InputText(label, buffer, sizeof(buffer));
        if (changed) {
            *str = buffer;
        }
        return changed;
    }

    bool InputTextWithHint(const char* label, const char* hint, std::string* str) {
        static char buffer[256];
        strcpy_s(buffer, sizeof(buffer), str->c_str());
        bool changed = ImGui::InputTextWithHint(label, hint, buffer, sizeof(buffer));
        if (changed) {
            *str = buffer;
        }
        return changed;
    }
}

