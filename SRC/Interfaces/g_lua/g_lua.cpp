#include "../../sdk.h"

void g_lua::SetLuaShared(CLuaShared * lua)
{
	lua_shared = lua;
}

CLuaShared * g_lua::GetLuaShared()
{
	return lua_shared;
}

ILuaInterface* g_lua::GetMenuState()
{
	return lua_shared->GetLuaInterface(LUA_MENU);
}

ILuaInterface* g_lua::GetClientState()
{
	return lua_shared->GetLuaInterface(LUA_CLIENT);
}

g_lua *g_Interfaces::lua = new g_lua;
