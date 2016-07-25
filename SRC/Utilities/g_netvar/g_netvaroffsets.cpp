#include "../../sdk.h"

void g_netvaroffsets::DumpNetvars()
{
	g_utilList::netvar->Start();
	g_utilList::netvar->DumpNetvars();

	// DT_BaseHLCombatWeapon
	m_iClip1 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseHLCombatWeapon", "m_iClip1"));
	m_iClip2 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseHLCombatWeapon", "m_iClip2"));
	m_flNextPrimaryAttack = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseHLCombatWeapon", "m_flNextPrimaryAttack"));

	// DT_BasePlayer
	m_flSimulationTime = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_flSimulationTime"));
	m_vecOrigin = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_vecOrigin"));
	m_Collision = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_Collision"));
	m_iTeamNum = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_iTeamNum"));
	m_bIsPlayerSimulated = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_bIsPlayerSimulated"));
	m_bSimulatedEveryTick = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_bSimulatedEveryTick"));
	m_iHealth = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_iHealth"));
	m_nSequence = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_nSequence"));
	m_iAmmo = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_iAmmo"));
	m_nTickBase = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_nTickBase"));
	m_vecViewOffset0 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_vecViewOffset[0]"));
	m_vecPunchAngle = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_vecPunchAngle"));
	m_vecVelocity0 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_vecVelocity[0]"));
	m_fFlags = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_fFlags"));
	m_iFOV = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_iFov"));
	m_bDucked = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_bDucked"));
	m_flLaggedMovementValue = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_flLaggedMovementValue"));
	m_lifeState = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_lifeState"));
	m_hObserverTarget = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BasePlayer", "m_hObserverTarget"));

	// DT_HL2MP_Player
	m_angEyeAngles0 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_HL2MP_Player", "m_angEyeAngles[0]"));
	m_angEyeAngles1 = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_HL2MP_Player", "m_angEyeAngles[1]"));

	// DT_BaseCombatCharacter
	m_flNextAttack = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseCombatCharacter", "m_flNextAttack"));
	m_hActiveWeapon = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseCombatCharacter", "m_hActiveWeapon"));

	// DT_BaseAnimating
	m_nHitboxSet = static_cast<DWORD>(g_utilList::netvar->GetOffset("DT_BaseAnimating", "m_nHitboxSet"));
}

g_netvaroffsets* g_utilList::offsets = new g_netvaroffsets;

