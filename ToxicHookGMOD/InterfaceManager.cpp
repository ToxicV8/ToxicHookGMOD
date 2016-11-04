#include "Includes.h"

InterfaceManager::InterfaceManager()
{

}


void InterfaceManager::FindInterfaces()
{
	g_pBaseClientDLL = new VTable<IBaseClientDLL>("client.dll", "VClient017");
	g_pEngineClient = new VTable<IVEngineClient>("engine.dll", "VEngineClient015");
	g_pEngineTrace = new VTable<IEngineTrace>("engine.dll", "EngineTraceClient003");
	g_pEntityList = new VTable<IClientEntityList>("client.dll", "VClientEntityList003");

	// + 5 to Skip  push ebp <- 1 Byte mov ebp, esp <- 2 Bytes mov ecx, <- 2 bytes
	DWORD Ptr = (*(DWORD**)g_pBaseClientDLL->Interface())[10] + 0x5;
	
	ClientModeShared* client_mode_shared = **(ClientModeShared***)(Ptr);

	g_pClientModeShared = new VTable<ClientModeShared>(client_mode_shared);
}

void InterfaceManager::Cleanup()
{
	delete g_pBaseClientDLL;
	delete g_pEngineTrace;
	delete g_pEntityList;
	delete g_pEngineClient;
	delete g_pClientModeShared;
}

InterfaceManager::~InterfaceManager()
{
	Cleanup();
}
