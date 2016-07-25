#pragma once

class CMoveHelper;
class CMoveData
{
public:
	char __pad0[0xFF];
};

class g_gamemovement
{
public:
	void ProcessMovement(CBaseEntity* pEntity, void* pMove);
};

class g_prediction
{
public:
	void SetupMove(CBaseEntity* pEntity, CUserCmd* pCmd, CMoveHelper* pHelper, void* move);
	void FinishMove(CBaseEntity* pEntity, CUserCmd* pCmd, void* move);
};

class g_movehelper
{
public:
	void SetHost(CBaseEntity*);
};