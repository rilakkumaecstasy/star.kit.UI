#include "in.h"

 
#ifdef star.ui.kit#1c34

   ▄▄▄▄▄      ▄▄▄▄▀ ██   █▄▄▄▄ █  █▀ ▄█    ▄▄▄▄▀ 
  █     ▀▄ ▀▀▀ █    █ █  █  ▄▀ █▄█   ██ ▀▀▀ █    
▄  ▀▀▀▀▄       █    █▄▄█ █▀▀▌  █▀▄   ██     █    
 ▀▄▄▄▄▀       █     █  █ █  █  █  █  ▐█    █     
             ▀         █   █     █    ▐   ▀      
                      █   ▀     ▀                
                     ▀                                 

       THIS UI IS VERY PRETTY UNLIKE OTHER PEOPLES SHITTY UIS CLEAN+SHORT - Rilakkumaecstasy

       hkp will keep overriding if u inject multiple times

       Этот пользовательский интерфейс очень красивый, в отличие от ужасных интерфейсов других людей, он чистый.


#endif 

DWORD WINAPI основной(LPVOID param)
{


    if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
    {
        kiero::bind(8, (void**)&globals::oPresent, (void*)hkp);
    }

    return 0;
}

BOOL __stdcall DllMain(HINSTANCE h, DWORD d)
{
    if (d == DLL_PROCESS_ATTACH)
    {
        HANDLE ket = CreateThread(nullptr, 0, основной, h, 0, nullptr);
        if (ket) CloseHandle(ket);
    }
    return TRUE;
}