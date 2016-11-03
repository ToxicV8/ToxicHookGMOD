#include "Includes.h"

InterfaceManager::InterfaceManager()
{

}


void InterfaceManager::FindInterfaces()
{
	g_pBaseClientDLL = new VTable<IBaseClientDLL>("client.dll", "VClient017");

	// + 5 to Skip  push ebp <- 1 Byte mov ebp, esp <- 2 Bytes mov ecx, <- 2 bytes
	DWORD Ptr = (*(DWORD**)g_pBaseClientDLL->Interface())[10] + 0x5;
	
	ClientModeShared* client_mode_shared = **(ClientModeShared***)(Ptr);

	g_pClientModeShared = new VTable<ClientModeShared>(client_mode_shared);
}

void InterfaceManager::Cleanup()
{
	delete g_pBaseClientDLL;
	delete g_pClientModeShared;
}

InterfaceManager::~InterfaceManager()
{
}
