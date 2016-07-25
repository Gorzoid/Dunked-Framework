#include "../../sdk.h"

void* g_hook::HookVMT(int iIndex, void* pOverride, void* pOrig, const char* szHook)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	g_utilList::console->Print(" Hooking %s... ", szHook);

	DWORD dwProtect;

	auto dwVFunc = static_cast<DWORD*>(pOrig) + sizeof(DWORD) * iIndex;
	int origFunc = *static_cast<DWORD*>(dwVFunc);
	VirtualProtect(static_cast<void*>(dwVFunc), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwProtect);
	*static_cast<DWORD*>(dwVFunc) = reinterpret_cast<DWORD>(pOverride);
	VirtualProtect(static_cast<void*>(dwVFunc), sizeof(DWORD), dwProtect, &dwProtect);

	g_utilList::console->Print("Hooked!\n");

	return reinterpret_cast<void*>(origFunc);
}

void* g_hook::UnHookVMT(int iIndex, void* pOrig, const char* szHook)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	g_utilList::console->Print(" UnHooking %s... ", szHook);

	DWORD dwProtect;

	auto dwVFunc = static_cast<DWORD*>(pOrig) + sizeof(DWORD) * iIndex;
	VirtualProtect(static_cast<void*>(dwVFunc), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwProtect);
	*static_cast<DWORD*>(dwVFunc) = reinterpret_cast<DWORD>(pOrig);
	VirtualProtect(static_cast<void*>(dwVFunc), sizeof(DWORD), dwProtect, &dwProtect);

	g_utilList::console->Print(" UnHooked!\n");

	return nullptr;
}

MODULEINFO g_hook::GetModuleInfo(char* szModule)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	MODULEINFO modinfo = { nullptr };
	auto hModule = GetModuleHandleA(szModule);
	if (hModule == nullptr)
		return modinfo;

	K32GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}

DWORD g_hook::dwFindPattern(char* hModule, char* szPattern, char* szMask, const char* szName)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	auto mInfo = GetModuleInfo(hModule);

	auto base = reinterpret_cast<DWORD>(mInfo.lpBaseOfDll);
	auto size = static_cast<DWORD>(mInfo.SizeOfImage);

	auto patternLength = static_cast<DWORD>(strlen(szMask));

	for (DWORD i = 0; i < size - patternLength; i++)
	{
		auto found = true;
		for (DWORD j = 0; j < patternLength; j++)
		{

			found &= szMask[j] == '?' || szPattern[j] == *reinterpret_cast<char*>(base + i + j);
		}

		if (found)
		{
			auto dwResult = base + i;
			g_utilList::console->Print(" Scannning Pattern %s... ", szName);
			g_utilList::console->Print("(");
			g_utilList::console->Print("0x%X", dwResult);
			g_utilList::console->Print(")\n");
			return base + i;
		}

	}

	g_utilList::console->Print("%s not found\n", szName);
	return NULL;
}

g_hook* g_utilList::hook = new g_hook;