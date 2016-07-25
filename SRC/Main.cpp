/*
	****************************
	      Dunked-Framework
	****************************
	Project Started: 23/07/2016
	Project By: Phage

	Credits to:
		Ley - For starting the original project
		Mythik - For giving me the idea to write my own
		Senator@cheater.team - Tons of help, collabed with many many cheats, many more in the future
*/
#include "sdk.h"

unsigned int __stdcall Dunked::Init(void*)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	g_utilList::console->Create("Dunked-Framework");
	g_utilList::console->Visible(true);

	g_utilList::console->centerPrint("*****************************************************************************\n");
	g_utilList::console->centerPrint("Dunked-Framework\n");
	g_utilList::console->centerPrint(" By Phage\n");
	g_utilList::console->centerPrint("*****************************************************************************\n");
	g_utilList::console->Print(" Build Date: %s\n", BUILDDATE);
	g_utilList::console->Print(" Build Time: %s\n", BUILDTIME);

	g_Interfaces::grab->dump();
	g_utilList::offsets->DumpNetvars();

	Beep(512, 1000);
	return 1;
}

void Dunked::DeInit()
{
	// UtilList deallocate
	delete g_utilList::exception;
	delete g_utilList::console;
	delete g_utilList::hook;
	delete g_utilList::netvar;
	delete g_utilList::offsets;

	// Interface deallocate
	delete g_Interfaces::grab;
	delete g_Interfaces::client;
	delete g_Interfaces::globaldata;
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
