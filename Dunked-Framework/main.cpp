/*
	****************************
	      Dunked-Framework
	****************************
	Project Started: 23/07/2016
	Project By: Phage
*/

#include "sdk.h"

unsigned int __stdcall g_ThreadStart(void*)
{
	Beep(512, 1000); // Confirmation for an successful injection
	return 0;
}

extern "C" int __stdcall DLLMain(HMODULE hModule, DWORD dwReason, void*)
{
	void* hThread;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);

		hThread = reinterpret_cast<void*>(_beginthreadex(nullptr, 0, &g_ThreadStart, nullptr, 0, nullptr));
		CloseHandle(hThread);
		break;

	case DLL_PROCESS_DETACH:
		_endthreadex(0);
		break;
	}

	return 1;
}