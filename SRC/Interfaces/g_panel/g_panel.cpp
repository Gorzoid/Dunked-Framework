#include "../../sdk.h"

const char* g_panel::GetName(unsigned int panel)
{
	typedef const char*(__thiscall* vFuncFn)(void*, unsigned int);
	return vfunc<vFuncFn>(this, 36)(this, panel);
}

g_panel* g_Interfaces::panel = new g_panel;