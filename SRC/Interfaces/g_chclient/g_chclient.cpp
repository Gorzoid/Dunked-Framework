#include "../../sdk.h"

ClientList* g_chclient::GetAllClasses()
{
	typedef ClientList*(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 8)(this);
}

g_chclient* g_Interfaces::client = new g_chclient;
g_globaldata* g_Interfaces::globaldata = new g_globaldata;