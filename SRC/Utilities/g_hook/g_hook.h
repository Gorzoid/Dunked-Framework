#pragma once

class g_hook
{
public:
	static void* HookVMT(int iIndex, void* pOverride, void* pOrig, const char* szHook);
	static void* UnHookVMT(int iIndex, void* pOrig, const char* szHook);
	static MODULEINFO GetModuleInfo(char* szModule);
	static DWORD dwFindPattern(char* hModule, char* szPattern, char* szMask, const char* szName);
};