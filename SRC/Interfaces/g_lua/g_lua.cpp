#include "../../sdk.h"

g_lua::g_lua(CLuaShared * lua)
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
