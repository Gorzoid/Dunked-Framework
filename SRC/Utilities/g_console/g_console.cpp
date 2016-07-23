#include "../../sdk.h"

void g_console::Create(char* chTitle)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	AllocConsole();
	auto hwnd = GetConsoleWindow();
	auto hMenu = GetSystemMenu(hwnd, FALSE);
	if (!hwnd || !hMenu) return;
	DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);

	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);

	SetConsoleTitleA(chTitle);

	g_utilList::console->bOpen = false;
}

void g_console::SetColor(color eColor)
{
	static auto Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, *reinterpret_cast<WORD*>(&eColor));
}

void g_console::Print(color eColor, std::string sMessage, ...)
{
	char buf[1024];
	va_list vlist;
	va_start(vlist, sMessage);
	_vsnprintf(buf, sizeof(buf), sMessage.c_str(), vlist);
	va_end(vlist);

	SetColor(eColor);
	printf("%s", buf);
	SetColor(color::WHITE);
}

void g_console::Print(std::string sMessage, ...)
{
	char buf[1024];
	va_list vlist;
	va_start(vlist, sMessage);
	_vsnprintf(buf, sizeof(buf), sMessage.c_str(), vlist);
	va_end(vlist);

	SetColor(color::WHITE);
	printf("%s", buf);
	SetColor(color::WHITE);
}

void g_console::centerPrint(color eColor, const char* sMessage)
{
	int l = strlen(sMessage);
	auto pos = static_cast<int>((80 - l) / 2);
	for (auto i = 0; i<pos; i++)
		g_utilList::console->Print(color::WHITE, " ");

	g_utilList::console->Print(eColor, sMessage);
}

void g_console::Visible(bool bVisible)
{
	g_utilList::exception->traceLastFunction(__FUNCSIG__, __FUNCDNAME__);

	AllocConsole();
	ShowWindow(FindWindowA("ConsoleWindowClass", nullptr), bVisible);
	g_utilList::console->bOpen = bVisible;
};

g_console* g_utilList::console = new g_console;