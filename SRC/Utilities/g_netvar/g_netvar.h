#pragma once

typedef void(*RecvVarProxyFn)(const CRecvProxyData* pData, void* pStruct, void* pOut);

class ClientList
{
public:
	void* m_pCreateFn;
	void* m_pCreateEventFn;
	const char* m_pNetworkName;
	RecvTable* m_pRecvTable;
	ClientList* m_pNext;
	int m_ClassID;
};

#ifdef GetProp
	#undef GetProp
#endif

class g_netvar
{
public:
	void Start();
	// calls GetProp wrapper to get the absolute offset of the prop
	int GetOffset(const char* tableName, const char* propName) const;

	// calls GetProp wrapper to get prop and sets the proxy of the prop, returns old proxy
	RecvVarProxyFn HookProp(const char* tableName, const char* propName, RecvVarProxyFn function) const;

	// wrapper so we can use recursion without too much performance loss
	int GetProp(const char* tableName, const char* propName, RecvProp** prop = nullptr) const;

	// uses recursion to return a the relative offset to the given prop and sets the prop param
	int GetProp(RecvTable* recvTable, const char* propName, RecvProp** prop = nullptr) const;

	RecvTable* GetTable(const char* tableName) const;
	void DumpTable(RecvTable* table) const;
	void DumpNetvars() const;
	std::vector<RecvTable*> m_tables;
};