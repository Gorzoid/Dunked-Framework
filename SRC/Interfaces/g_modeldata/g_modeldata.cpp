#include "../../sdk.h"

const char* g_modeldata::GetModelName(const model_t* model)
{
	typedef const char* (__thiscall* vFuncFn)(void*, const model_t*);
	return vfunc<vFuncFn>(this, 4)(this, model);
}

studiohdr_t* g_modeldata::GetStudioModel(const model_t* mod)
{
	typedef studiohdr_t* (__thiscall* vFuncFn)(void*, const model_t*);
	return vfunc<vFuncFn>(this, 29)(this, mod);
}

g_modeldata* g_Interfaces::modeldata = new g_modeldata;