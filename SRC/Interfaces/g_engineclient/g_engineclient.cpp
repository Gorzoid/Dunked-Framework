#include "../../sdk.h"

void g_engineclient::SetViewAngles(Angle& vAngle)
{
	typedef void(__thiscall* vFuncFn)(void*, Angle&);
	return vfunc<vFuncFn>(this, 20)(this, vAngle);
}

void g_engineclient::GetScreenSize(int& iWidth, int& iHeight)
{
	typedef void(__thiscall* vFuncFn)(void*, int&, int&);
	return vfunc<vFuncFn>(this, 5)(this, iWidth, iHeight);
}

void g_engineclient::ClientCmd(const char* chText)
{
	typedef void(__thiscall* vFuncFn)(void*, const char*);
	return vfunc<vFuncFn>(this, 106)(this, chText);
}

int g_engineclient::GetLocalPlayer()
{
	typedef int(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 12)(this);
}

bool g_engineclient::GetPlayerInfo(int iNum, player_info_t* pinfo)
{
	typedef bool(__thiscall* vFuncFn)(void*, int, player_info_t*);
	return vfunc<vFuncFn>(this, 8)(this, iNum, pinfo);
}

bool g_engineclient::IsInGame()
{
	typedef bool(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 26)(this);
}

int g_engineclient::GetMaxClients(void)
{
	typedef int(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 21)(this);
}

const Matrix4x4& g_engineclient::WorldToScreenMatrix(void)
{
	typedef const Matrix4x4& (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 36)(this);
}

g_engineclient* g_Interfaces::engine = new g_engineclient;