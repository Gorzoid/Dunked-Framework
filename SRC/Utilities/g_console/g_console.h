#pragma once

class g_console
{
public:
	bool bOpen;
	static void Create(char*);
	static void Print(std::string sMessage, ...);
	static void centerPrint(const char* sMessage);
	static void Visible(bool);
};