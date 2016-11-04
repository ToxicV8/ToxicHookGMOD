#include "Includes.h"

/*Pointer*/
Utilities* g_pUtils = new Utilities;
Logger* g_pLogger = new Logger;
HackManager* g_pHackManager = new HackManager;
Globals* g_pGlobals = new Globals;
InterfaceManager* g_pInterfaceManager = new InterfaceManager;
HookManager* g_pHookManager = new HookManager;
NetVarManager* g_pNetVarManager;

/*Interface Pointer*/
VTable<IBaseClientDLL>* g_pBaseClientDLL;
VTable<ClientModeShared>* g_pClientModeShared;
VTable<IVEngineClient>* g_pEngineClient;
VTable<IClientEntityList>* g_pEntityList;
VTable<IEngineTrace>* g_pEngineTrace;