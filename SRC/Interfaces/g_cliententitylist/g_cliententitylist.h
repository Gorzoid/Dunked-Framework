#pragma once

struct player_info_t;
class ClientList;
class model_t;

struct mstudiobone_t
{
	int			sznameindex;
	int			parent;
	int			bonecontroller[6];
	Vector		pos;
	float		quat[4];
	Vector		rot;
	Vector		posscale;
	Vector		rotscale;
	Matrix3x4	poseToBone;
	float		qAlignment[4];
	int			flags;
	int			proctype;
	int			procindex;
	mutable int	physicsbone;
	int			surfacepropidx;
	int			contents;
	int			unused[8];

	const char* GetSurfaceProp(void) const
	{
		return (char*)this + surfacepropidx;
	}

	void* GetProcedure(void) const
	{
		if (!procindex)
			return nullptr;

		return static_cast<void*>((unsigned char*)this + procindex);
	}

	const char* GetName(void) const
	{
		return (char*)this + sznameindex;
	}
};

struct mstudiobbox_t
{
	int		bone;
	int		group;
	Vector	bbmin;
	Vector	bbmax;
	int		szhitboxnameindex;
	int		unused[8];

	const char* GetHitboxName(void) const
	{
		if (!szhitboxnameindex)
			return "";

		return (char*)this + szhitboxnameindex;
	}
};

struct mstudiohitboxset_t
{
	int	sznameindex;
	int	numhitboxes;
	int	hitboxindex;

	mstudiobbox_t* GetHitbox(int i) const
	{
		return reinterpret_cast<mstudiobbox_t*>((unsigned char*)this + hitboxindex) + i;
	}

	const char* GetName(void) const
	{
		return (char*)this + sznameindex;
	}
};

struct studiohdr_t
{
	int			id;
	int			version;

	long		checksum;

	char		name[64];
	int			length;

	Vector		eyeposition;
	Vector		illumposition;

	Vector		hull_min;
	Vector		hull_max;

	Vector		view_bbmin;
	Vector		view_bbmax;

	int			flags;

	int			numbones;
	int			boneindex;

	int			numbonecontrollers;
	int			bonecontrollerindex;

	int			numhitboxsets;
	int			hitboxsetindex;

	int			numlocalanim;
	int			localanimindex;

	int			numlocalseq;
	int			localseqindex;

	mutable int	activitylistversion;
	mutable int	eventsindexed;

	int			numtextures;
	int			textureindex;

	int GetHitboxCount(int set) const
	{
		auto pSet = GetHitboxSet(set);

		if (!pSet)
			return 0;

		return pSet->numhitboxes;
	}

	mstudiohitboxset_t* GetHitboxSet(int i) const
	{
		return reinterpret_cast<mstudiohitboxset_t*>((unsigned char*)this + hitboxsetindex) + i;
	}

	mstudiobbox_t* GetHitbox(int i, int set) const
	{
		mstudiohitboxset_t* pSet = GetHitboxSet(set);

		if (!pSet)
			return nullptr;

		return pSet->GetHitbox(i);
	}

	mstudiobone_t* GetBone(int i) const
	{
		return reinterpret_cast<mstudiobone_t*>((unsigned char*)this + boneindex) + i;
	}

	const char* GetName(void) const
	{
		return name;
	}
};

class CBaseWeapon
{
public:
	const char* GetName();
	int& GetClip1();
	float GetNextAttackTime();
};

class CBaseEntity
{
public:
	void* GetRenderableEntity();
	void* GetNetworkEntity();
	void* GetCollideable();
	const Vector& GetMins();
	const Vector& GetMaxs();
	ClientList* GetList();
	int GetFOV();
	CBaseWeapon* GetWeapon();
	const model_t* GetModel();
	float GetNextAttackTime();
	bool CanAttack();
	bool CanFire();
	bool SetupBones(Matrix3x4* pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime);
	static bool GetBonePosition(int iBone, Vector& vOut);
	bool GetHitboxPosition(int iHitbox, Vector& vOut);
	bool IsDormant();
	int GetIndex();
	int GetHitboxHandle();
	int EntityFlags();
	const Vector& GetAbsOrigin();
	bool IsPlayer();
	player_info_t info();
	bool Ducked();
	Angle GetPunch();
	Vector GetVelocity();
	Vector HeadOffset();
	Vector GetHeadPosition();
	float GetLaggedMovement();
	bool IsAlive();
	int GetHealth();
	int GetTickBase();
	void SetPunchAngle(const Angle& vecPunchAngle);
	void SetTickBase(int nTickBase);
	int GetTeam();
	CBaseEntity GetObserver();
	float SimulationTime();
};

class g_cliententitylist
{
public:
	CBaseEntity* GetClientEntity(int entnum);
	CBaseEntity* GetClientEntityFromHandle(unsigned long hEnt);
	int GetHighestEntityIndex();
};

