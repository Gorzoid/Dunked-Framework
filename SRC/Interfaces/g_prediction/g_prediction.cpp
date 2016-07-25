#include "../../sdk.h"

void g_gamemovement::ProcessMovement(CBaseEntity* pEntity, void* pMove)
{
	typedef void(__thiscall* vFuncFn)(void*, CBaseEntity*, void*);
	vfunc<vFuncFn>(this, 1)(this, pEntity, pMove);
}

void g_prediction::SetupMove(CBaseEntity* pEntity, CUserCmd* pCmd, CMoveHelper* pHelper, void* move)
{
	typedef void(__thiscall* vFuncFn)(void*, CBaseEntity*, CUserCmd*, CMoveHelper*, void*);
	vfunc<vFuncFn>(this, 19)(this, pEntity, pCmd, pHelper, move);
}

void g_prediction::FinishMove(CBaseEntity* pEntity, CUserCmd* pCmd, void* move)
{
	typedef void(__thiscall* vFuncFn)(void*, CBaseEntity*, CUserCmd*, void*);
	vfunc<vFuncFn>(this, 20)(this, pEntity, pCmd, move);
}

void g_movehelper::SetHost(CBaseEntity* pEntity)
{
	typedef void(__thiscall* vFuncFn)(void*, CBaseEntity*);
	vfunc<vFuncFn>(this, 1)(this, pEntity);
}

g_gamemovement* g_Interfaces::gamemovement = new g_gamemovement;
g_prediction* g_Interfaces::prediction = new g_prediction;
g_movehelper* g_Interfaces::movehelper = new g_movehelper;

