#include "../../sdk.h"

int g_debugoverlay::ScreenPosition(const Vector& point, Vector& screen)
{
	typedef int(__thiscall* vFn)(void*, const Vector&, Vector&);
	return vfunc<vFn>(this, 9)(this, point, screen);
}

g_debugoverlay* g_Interfaces::debugoverlay = new g_debugoverlay;

