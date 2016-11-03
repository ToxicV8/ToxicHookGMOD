#include "Includes.h"


BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH )
	{
		g_pHackManager->Start();
	}

	if(dwReason == DLL_PROCESS_DETACH )
	{
		g_pHackManager->Stop();

		delete g_pHackManager;
	}

	return true;
}

