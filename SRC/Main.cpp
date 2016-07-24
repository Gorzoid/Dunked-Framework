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

	g_utilList::console->centerPrint("*****************************************************************************\n");
	g_utilList::console->centerPrint("Dunked-Framework\n");
	g_utilList::console->centerPrint(" By Phage\n");
	g_utilList::console->centerPrint("*****************************************************************************\n");
	g_utilList::console->Print(" Build Date: %s\n", BUILDDATE);
	g_utilList::console->Print(" Build Time: %s\n", BUILDTIME);

	Beep(512, 1000);
	return 0;
}

void Dunked::DeInit()
{
	delete g_utilList::console;
	delete g_utilList::exception;
}

void DLLMainInit(HMODULE hModule)
{
	void* pThread;
	unsigned int id;

	_G::hDLLModule = hModule;
	SetUnhandledExceptionFilter(g_utilList::exception->unhandledExceptionFilter);

	do
	{
		pThread = reinterpret_cast<void*>(_beginthreadex(nullptr, NULL, Dunked::Init, nullptr, 0, &id));
	} while (pThread == nullptr);

	DisableThreadLibraryCalls(hModule);
	CloseHandle(pThread);
}

extern "C" int __stdcall DllMain(HMODULE hModule, DWORD dwReason, void*)
{	
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DLLMainInit(hModule);
		break;

	case DLL_PROCESS_DETACH:
		Dunked::DeInit();
		break;
	}

	return TRUE;
}
