#include "Includes.h"

bool __fastcall hkCreateMove(void* thisptr, void* esp, float smt, CUserCmd* cmd)
{
	if (cmd->command_number == 0 || !g_pEngineClient->Interface()->IsInGame())
		return false;
	
	g_pGlobals->LocalPlayer = (CBaseEntity*)g_pEntityList->Interface()->GetClientEntity(g_pEngineClient->Interface()->GetLocalPlayer());
	
	return false;
}