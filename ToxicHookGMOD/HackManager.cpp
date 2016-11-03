#include "Includes.h"


HackManager::HackManager()
{

}

void HackManager::Start()
{
	g_pLogger->Initialize();

	g_pLogger->Log("Console started");
}

void HackManager::Stop()
{
	g_pLogger->Log("Shutting down...");

	g_pLogger->Terminate();
	
	delete g_pUtils;
	delete g_pGlobals;
	delete g_pLogger;
}


HackManager::~HackManager()
{

}
