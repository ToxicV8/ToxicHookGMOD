#include "Includes.h"



NetVarManager::NetVarManager()
{
	m_tables.clear();

	ClientClass *clientClass = g_pBaseClientDLL->Interface()->GetAllClasses();

	if (!clientClass)
		return;

	while (clientClass)
	{
		RecvTable *recvTable = clientClass->m_pRecvTable;

		m_tables.emplace_back(recvTable);

		clientClass = clientClass->m_pNext;
	}
}

void NetVarManager::FindOffsets()
{
	FIND_NETVAR("DT_BasePlayer", "m_iHealth");
	FIND_NETVAR("DT_BasePlayer", "m_iTeamNum");
	FIND_NETVAR("DT_BasePlayer", "m_vecOrigin");
}

int NetVarManager::GetOffset(const char* tableName, const char* propName)
{
	int offset = GetProperty(tableName, propName);

	if (!offset)
	{
		g_pLogger->Log("[NetVarManager] Could not find %s", propName);
		return 0;
	}

	g_pLogger->Log("[NetVarManager] Found %s at 0x%X", propName, offset);

	return offset;
}

bool NetVarManager::HookProperty(const char *tableName, const char *propName, RecvVarProxyFn function)
{
	RecvProp *recvProp = 0;

	GetProperty(tableName, propName, &recvProp);

	if (!recvProp)
		return false;

	recvProp->m_ProxyFn = function;

	return true;
}

int NetVarManager::GetProperty(const char *tableName, const char *propName, RecvProp **prop)
{
	RecvTable *recvTable = GetTable(tableName);

	if (!recvTable)
		return 0;

	int offset = GetProperty(recvTable, propName, prop);

	if (!offset)
		return 0;

	return offset;
}

int NetVarManager::GetProperty(RecvTable *recvTable, const char *propName, RecvProp **prop)
{
	int extraOffset = 0;

	for (int i = 0; i < recvTable->m_nProps; ++i) // Loop through all propertys
	{
		RecvProp *recvProp = &recvTable->m_pProps[i];

		RecvTable *child = recvProp->m_pDataTable;

		if (child && child->m_nProps > 0)
		{
			int temporary = GetProperty(child, propName, prop);

			if (temporary)
				extraOffset += (recvProp->m_Offset + temporary);
		}

		if (stricmp(recvProp->m_pVarName, propName))
			continue;


		if (prop)
			*prop = recvProp;

		return (recvProp->m_Offset + extraOffset);
	}

	return extraOffset;
}

RecvTable *NetVarManager::GetTable(const char *tableName)
{
	if (m_tables.empty())
		return 0;

	for(RecvTable* table : m_tables)
	{
		if (table && stricmp(table->m_pNetTableName, tableName) == 0)
			return table;
	}

	return 0;
}


NetVarManager::~NetVarManager()
{
}
