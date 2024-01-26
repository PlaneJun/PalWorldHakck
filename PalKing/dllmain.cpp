#include <windows.h>
#include "cheat.h"


void initialize()
{
    cheat::get_instance()->init();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (DLL_PROCESS_ATTACH == ul_reason_for_call)
    {
        initialize();
    }
    return TRUE;
}

