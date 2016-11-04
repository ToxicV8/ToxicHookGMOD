#include "Includes.h"

CBaseEntity::CBaseEntity()
{
	
}

Vector CBaseEntity::GetOrigin()
{
	return READ_NETVAR(Vector, "m_vecOrigin");
}

int CBaseEntity::GetHealth()
{
	return READ_NETVAR(int, "m_iHealth");
}

int CBaseEntity::GetTeam()
{
	return READ_NETVAR(int, "m_iTeamNum");
}


bool CBaseEntity::IsVisible(Vector start)
{
	
}

CBaseEntity::~CBaseEntity()
{
	
}
