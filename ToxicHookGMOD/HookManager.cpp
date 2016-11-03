#include "Includes.h"

#pragma region HookFunctions
extern bool __fastcall hkCreateMove(void* thisptr, void* esp, float smt, CUserCmd* cmd);
#pragma endregion

HookManager::HookManager()
{

}

void HookManager::Hook()
{
	g_pClientModeShared->HookFunction(21, reinterpret_cast<DWORD>(hkCreateMove));
}

HookManager::~HookManager()
{
}
