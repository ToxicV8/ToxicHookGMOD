#include "Includes.h"



NetVarManager::NetVarManager()
{
	m_tables.clear();

	ClientClass *clientClass = g_pBaseClientDLL->Interface()->GetAllClasses();

	while (clientClass)
	{
		m_tables.emplace_back(clientClass->m_pRecvTable);
		clientClass = clientClass->m_pNext;
	}
}

void NetVarManager::FindOffsets()
{
	FIND_NETVAR("DT_BaseEntity", "m_iTeamNum");
	FIND_NETVAR("DT_BaseEntity", "m_iHealth");
	FIND_NETVAR("DT_BaseEntity", "m_vecOrigin");
}

int NetVarManager::GetOffset(const char* tableName, const char* propName)
{
	int offset = GetProperty(tableName, propName);

	if (!offset)
	{
		g_pLogger->Log("[NetVarManager] Could not find %s::%s", tableName, propName);
		return 0;
	}

	g_pLogger->Log("[NetVarManager] Found %s::%s at 0x%X", tableName, propName, offset);

	return offset;
}

bool NetVarManager::HookProperty(const char *tableName, const char *propName, RecvVarProxyFn function)
{
	RecvProp *recvProp = 0;

	GetProperty(tableName, propName, &recvProp);

	if (!recvProp)
		return false;

	recvProp->SetProxyFn(function);

	return true;
}

int NetVarManager::GetProperty(const char *tableName, const char *propName, RecvProp **prop)
{
	RecvTable *recvTable = this->GetTable(tableName);

	if (!recvTable)
		return 0;

	int offset = this->GetProperty(recvTable, propName, prop);

	if (!offset)
		return 0;

	return offset;
}

int NetVarManager::GetProperty(RecvTable *recvTable, const char *propName, RecvProp **prop)
{
	int extraOffset = 0;

	for (int i = 0; i < recvTable->GetNumProps(); ++i) // Loop through all propertys
	{
		RecvProp *recvProp = recvTable->Get_Prop(i);

		RecvTable *child = recvProp->GetDataTable();

		if (child && (child->GetNumProps() > 0))
		{
			int temporary = this->GetProperty(child, propName, prop);

			if (temporary)
				extraOffset += (recvProp->GetOffset() + extraOffset);
		
		}

		if (stricmp(recvProp->GetName(), propName))
			continue;

		if (prop)
			*prop = recvProp;
		
		return (recvProp->GetOffset() + extraOffset);
	}

	return extraOffset;
}

RecvTable *NetVarManager::GetTable(const char *tableName)
{
	for(RecvTable* table : m_tables)
	{
		if (table && !stricmp(table->m_pNetTableName, tableName))
			return table;
	}

	return 0;
}


NetVarManager::~NetVarManager()
{
}
