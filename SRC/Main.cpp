/*
	****************************
	      Dunked-Framework
	****************************
	Project Started: 23/07/2016
	Project By: Phage

	Credits to:
		Ley - For starting the original project
		Mythik - For giving me the idea to write my own
		Senator@cheater.team
*/
#include "sdk.h"

unsigned int __stdcall Dunked::Init(void*)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	g_utilList::console->Create("BRITWEBZ");
	g_utilList::console->Visible(true);

	g_utilList::console->centerPrint(color::WHITE, "*****************************************************************************\n");
	g_utilList::console->centerPrint(color::RED, "B R I T  W E B Z\n");
	g_utilList::console->centerPrint(color::WHITE, "By Senator & Phage\n");
	g_utilList::console->centerPrint(color::WHITE, "*****************************************************************************\n");
	g_utilList::console->Print(" Build Date: %s\n", BUILDDATE);
	g_utilList::console->Print(" Build Time: %s\n", BUILDTIME);

	MessageBoxA(nullptr, "gay", "gay", MB_OK);
	Beep(512, 1000);
	return 1;
}

extern "C" int __stdcall DLLMain(HMODULE hModule, DWORD dwReason, void*)
{
	void* pThread;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		_G::hDLLModule = hModule;
		SetUnhandledExceptionFilter(g_utilList::exception->unhandledExceptionFilter);

		pThread = reinterpret_cast<void*>(_beginthreadex(nullptr, NULL, &Dunked::Init, nullptr, NULL, nullptr));
		CloseHandle(pThread);
		break;

	case DLL_PROCESS_DETACH:
		_endthreadex(0);
		break;
	}

	return TRUE;
}