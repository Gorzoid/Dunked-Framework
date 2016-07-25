#include "../../sdk.h"

void* CBaseEntity::GetRenderableEntity()
{
	return static_cast<void*>(this + 0x4);
}

void* CBaseEntity::GetNetworkEntity()
{
	return static_cast<void*>(this + 0x8);
}

void* CBaseEntity::GetCollideable()
{
	typedef void* (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 3)(this);
}

const Vector& CBaseEntity::GetMins()
{
	auto pCollide = GetCollideable();
	typedef const Vector& (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pCollide, 1)(pCollide);
}

const Vector& CBaseEntity::GetMaxs()
{
	auto pCollide = GetCollideable();
	typedef const Vector& (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pCollide, 2)(pCollide);
}

ClientList* CBaseEntity::GetList()
{
	auto pNetworkEntity = GetNetworkEntity();
	typedef ClientList* (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pNetworkEntity, 2)(pNetworkEntity);
}

int CBaseEntity::GetFOV()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_iFOV);
}

CBaseWeapon* CBaseEntity::GetWeapon()
{
	return reinterpret_cast<CBaseWeapon*>(g_Interfaces::entlist->GetClientEntityFromHandle(*reinterpret_cast<unsigned long*>(this + g_utilList::offsets->m_hActiveWeapon)));
}

float CBaseEntity::GetNextAttackTime()
{
	return *reinterpret_cast<float*>(this + g_utilList::offsets->m_flNextAttack);
}

bool CBaseEntity::CanAttack()
{
	return (GetNextAttackTime() <= this->GetTickBase() * g_Interfaces::globaldata->interval_per_tick);
}

bool CBaseEntity::CanFire()
{
	return (GetWeapon()->GetNextAttackTime() <= this->GetTickBase() * g_Interfaces::globaldata->interval_per_tick);
}

bool CBaseEntity::SetupBones(Matrix3x4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
{
	auto ren = GetRenderableEntity();

	typedef bool(__thiscall* vFuncFn)(void*, Matrix3x4*, int, int, float);
	return vfunc<vFuncFn>(ren, 15)(ren, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
}

bool CBaseEntity::GetBonePosition(int iBone, Vector& vOut)
{
	Matrix3x4 vMatrix[128];

	vOut.x = vMatrix[iBone][0][3];
	vOut.y = vMatrix[iBone][1][3];
	vOut.z = vMatrix[iBone][2][3];

	return !vOut.IsZero();
}

bool CBaseEntity::GetHitboxPosition(int iHitbox, Vector& vOut)
{
	Matrix3x4 vMatrix[128];

	auto pModel = GetModel();

	if (!pModel)
		return false;

	auto pStudioHdr = g_Interfaces::modeldata->GetStudioModel(pModel);

	if (!pStudioHdr)
		return false;

	auto pSet = pStudioHdr->GetHitboxSet(GetHitboxHandle());

	if (!pSet)
		return false;

	auto pBox = pSet->GetHitbox(iHitbox);

	if (!pBox)
		return false;

	Vector vMin, vMax;
	g_utilList::math->Transform(pBox->bbmin, vMatrix[pBox->bone], vMin);
	g_utilList::math->Transform(pBox->bbmax, vMatrix[pBox->bone], vMax);

	vOut = (vMin + vMax) * .5f;

	return !vOut.IsZero();
}

const model_t* CBaseEntity::GetModel(void)
{
	auto pRenderableEntity = GetRenderableEntity();

	typedef const model_t* (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pRenderableEntity, 8)(pRenderableEntity);
}

bool CBaseEntity::IsDormant()
{
	auto pNetworkEntity = GetNetworkEntity();
	typedef bool(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pNetworkEntity, 8)(pNetworkEntity);
}

int CBaseEntity::GetIndex()
{
	auto pNetworkEntity = GetNetworkEntity();
	typedef int(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(pNetworkEntity, 9)(pNetworkEntity);
}


int CBaseEntity::GetHitboxHandle()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_nHitboxSet);
}

int CBaseEntity::EntityFlags()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_fFlags);
}

const Vector& CBaseEntity::GetAbsOrigin(void)
{
	typedef const Vector& (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 9)(this);
}

bool CBaseEntity::IsPlayer()
{
	typedef bool(__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 118)(this);
}

player_info_t CBaseEntity::info()
{
	player_info_t pInfo;
	g_Interfaces::engine->GetPlayerInfo(this->GetIndex(), &pInfo);

	return pInfo;
}

// Weapon Information

const char* CBaseWeapon::GetName()
{
	typedef const char* (__thiscall* vFuncFn)(void*);
	return vfunc<vFuncFn>(this, 260)(this);
}

int& CBaseWeapon::GetClip1()
{
	return *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(this + g_utilList::offsets->m_iClip1));
}

float CBaseWeapon::GetNextAttackTime()
{
	return *reinterpret_cast<float*>(this + g_utilList::offsets->m_flNextPrimaryAttack);
}

// Netvar Data Information

bool CBaseEntity::Ducked()
{
	return *reinterpret_cast<bool*>(this + g_utilList::offsets->m_bDucked);
}

Angle CBaseEntity::GetPunch()
{
	return *reinterpret_cast<Angle*>(this + g_utilList::offsets->m_vecPunchAngle);
}

void CBaseEntity::SetPunchAngle(const Angle& vecPunchAngle)
{
	*reinterpret_cast<Angle*>(this + g_utilList::offsets->m_vecPunchAngle) = vecPunchAngle;
}

Vector CBaseEntity::GetVelocity()
{
	return *reinterpret_cast<Vector*>(this + g_utilList::offsets->m_vecVelocity0);
}

Vector CBaseEntity::HeadOffset()
{
	return *reinterpret_cast<Vector*>(this + g_utilList::offsets->m_vecViewOffset0);
}

Vector CBaseEntity::GetHeadPosition()
{
	return static_cast<Vector>(this->GetAbsOrigin()) + this->HeadOffset();
}

float CBaseEntity::GetLaggedMovement()
{
	return *reinterpret_cast<float*>(this + g_utilList::offsets->m_flLaggedMovementValue);
}

bool CBaseEntity::IsAlive()
{
	return !*reinterpret_cast<bool*>(this + g_utilList::offsets->m_lifeState);
}

int CBaseEntity::GetHealth()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_iHealth);
}

int CBaseEntity::GetTickBase()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_nTickBase);
}

void CBaseEntity::SetTickBase(int nTickBase)
{
	*reinterpret_cast<int*>(this + g_utilList::offsets->m_nTickBase) = nTickBase;
}

int CBaseEntity::GetTeam()
{
	return *reinterpret_cast<int*>(this + g_utilList::offsets->m_iTeamNum);
}

CBaseEntity CBaseEntity::GetObserver()
{
	return *reinterpret_cast<CBaseEntity*>(this + g_utilList::offsets->m_hObserverTarget);
}

float CBaseEntity::SimulationTime()
{
	return *reinterpret_cast<float*>(this + g_utilList::offsets->m_flSimulationTime);
}

// Interface Functions

CBaseEntity* g_cliententitylist::GetClientEntity(int entnum)
{
	typedef CBaseEntity* (__thiscall* vFunc)(void*, int);
	return vfunc<vFunc>(this, 3)(this, entnum);
}

CBaseEntity* g_cliententitylist::GetClientEntityFromHandle(unsigned long hEnt)
{
	typedef CBaseEntity* (__thiscall* vFunc)(void*, unsigned long);
	return vfunc<vFunc>(this, 4)(this, hEnt);
}

int g_cliententitylist::GetHighestEntityIndex(void)
{
	typedef int(__thiscall* vFunc)(void*);
	return vfunc<vFunc>(this, 6)(this);
}

g_cliententitylist* g_Interfaces::entlist = new g_cliententitylist;

