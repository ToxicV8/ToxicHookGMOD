#include "Includes.h"


HackManager::HackManager()
{

}

void HackManager::Start()
{
	g_pLogger->Initialize();

	g_pLogger->Log("Console started");

	g_pLogger->Log("Searching Interfaces");

	g_pInterfaceManager->FindInterfaces();

	g_pLogger->Log("Scanning NetVars");
	
	g_pNetVarManager = new NetVarManager;

	g_pNetVarManager->FindOffsets();

	g_pLogger->Log("Hooking...");

	g_pHookManager->Hook();

	g_pLogger->Log("Setup successfully!");
}

void HackManager::Stop()
{
	g_pLogger->Log("Shutting down...");

	g_pLogger->Terminate();
	
	g_pInterfaceManager->Cleanup();

	delete g_pUtils;
	delete g_pGlobals;
	delete g_pLogger;
	delete g_pInterfaceManager;
	delete g_pNetVarManager;
	delete g_pHookManager;
}


HackManager::~HackManager()
{

}
