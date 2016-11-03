#include "Includes.h"

bool __fastcall hkCreateMove(void* thisptr, void* esp, float smt, CUserCmd* cmd)
{
	if (cmd->command_number == 0)
		return false;

	if (GetAsyncKeyState(VK_SPACE))
		cmd->viewangles.y = 89;

	return true;
}