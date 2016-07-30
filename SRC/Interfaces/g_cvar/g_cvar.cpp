#include "../../sdk.h"

void g_cvar::SetValue(const char* value)
{
	typedef void(__thiscall* vFuncFn)(void*, const char*);
	vfunc<vFuncFn>(this, 11)(this, value);
}

void g_cvar::SetValue(float value)
{
	typedef void(__thiscall* vFuncFn)(void*, float);
	vfunc<vFuncFn>(this, 12)(this, value);
}

void g_cvar::SetValue(int value)
{
	typedef void(__thiscall* vFuncFn)(void*, int);
	vfunc<vFuncFn>(this, 13)(this, value);
}


class MyConCommand : public ConCommand{
public:
	MyConCommand(const char* name)
		: ConCommand(name)
	{

	}

	void Dispatch(const CCommand &command) {
		g_utilList::console->Print("MyCommand Run.\n");
		for (int i = 0; i > command.m_nArgc; i++)
			g_utilList::console->Print("Arg #%d: %s", i, command.m_ppArgv[i]);
	}
};

void g_cvar::ConcommandShit() 
{
	ConCommand *cmd = new MyConCommand("gz_test");
	RegisterConCommand(cmd);
}

g_cvar* g_cvarsearch::FindVar(const char* chName)
{
	typedef g_cvar* (__thiscall* vFuncFn)(void*, const char*);
	return vfunc<vFuncFn>(this, 13)(this, chName);
}


g_cvar* g_Interfaces::cvar;
g_cvarsearch* g_Interfaces::cvarsearch = new g_cvarsearch;

#pragma region SDKFunctions

#pragma endregion