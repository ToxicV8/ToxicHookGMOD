#pragma once
#define GET_NETVAR(X) g_pNetVarManager->m_vOffsets[X]
#define FIND_NETVAR(X, Y) m_vOffsets[Y] = GetOffset(X, Y)

class NetVarManager
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="NetVarManager"/> class.
	/// </summary>
	NetVarManager(void);

	/// <summary>
	/// Finalizes an instance of the <see cref="NetVarManager"/> class.
	/// </summary>
	~NetVarManager();

	/// <summary>
	/// Gets the offset.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="propName">Name of the property.</param>
	/// <returns>The Offset of the NetVar</returns>
	int GetOffset(const char *tableName, const char *propName);

	/// <summary>
	/// Hooks the property.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="propName">Name of the property.</param>
	/// <param name="function">The function.</param>
	/// <returns></returns>
	bool HookProperty(const char *tableName, const char *propName, RecvVarProxyFn function);

	/// <summary>
	/// Finds the offsets.
	/// </summary>
	void FindOffsets();

	std::unordered_map<std::string, int> m_vOffsets;

private:
	/// <summary>
	/// Gets the property.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="propName">Name of the property.</param>
	/// <param name="prop">The property.</param>
	/// <returns></returns>
	int GetProperty(const char *tableName, const char *propName, RecvProp **prop = 0);

	/// <summary>
	/// Gets the property.
	/// </summary>
	/// <param name="recvTable">The recv table.</param>
	/// <param name="propName">Name of the property.</param>
	/// <param name="prop">The property.</param>
	/// <returns></returns>
	int GetProperty(RecvTable *recvTable, const char *propName, RecvProp **prop = 0);

	/// <summary>
	/// Gets the table.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns></returns>
	RecvTable *GetTable(const char *tableName);

	std::vector<RecvTable*> m_tables;
};

extern NetVarManager* g_pNetVarManager;