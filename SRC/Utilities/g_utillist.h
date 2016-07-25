#pragma once

#include "g/g.h"
#include "g_exception/g_exception.h"
#include "g_console/g_console.h"
#include "g_hook/g_hook.h"
#include "g_netvar/g_netvar.h"
#include "g_netvar/g_netvaroffsets.h"

namespace g_utilList
{
	extern g_exception* exception;
	extern g_console* console;
	extern g_hook* hook;
	extern g_netvar* netvar;
	extern g_netvaroffsets* offsets;
}