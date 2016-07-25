#pragma once

class g_netvaroffsets
{
public:
	void DumpNetvars();

	// Offsets

	// DT_BaseHLCombatWeapon  
	DWORD m_iClip1;
	DWORD m_iClip2;
	DWORD m_flNextPrimaryAttack;

	// DT_BasePlayer 
	DWORD m_flSimulationTime;
	DWORD m_vecOrigin;
	DWORD m_Collision;
	DWORD m_iTeamNum;
	DWORD m_bIsPlayerSimulated;
	DWORD m_bSimulatedEveryTick;
	DWORD m_iHealth;
	DWORD m_nSequence;
	DWORD m_iAmmo;
	DWORD m_nTickBase;
	DWORD m_vecViewOffset0;
	DWORD m_vecPunchAngle;
	DWORD m_vecVelocity0;
	DWORD m_fFlags;
	DWORD m_iFOV;
	DWORD m_bDucked;
	DWORD m_flLaggedMovementValue;
	DWORD m_lifeState;
	DWORD m_hObserverTarget;

	// DT_HL2MP_Player
	DWORD m_angEyeAngles0;
	DWORD m_angEyeAngles1;

	// DT_BaseCombatCharacter
	DWORD m_hActiveWeapon;
	DWORD m_flNextAttack;

	// DT_BaseAnimating
	DWORD m_nHitboxSet;
};

