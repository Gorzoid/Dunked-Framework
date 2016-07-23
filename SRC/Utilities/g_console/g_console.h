#pragma once

enum class color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKPINK,
	DARKYELLOW,
	LIGHTGREY,
	DARKGREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PINK,
	YELLOW,
	WHITE
};

class g_console
{
public:
	bool bOpen;
	static void Create(char*);
	static void SetColor(color);
	static void Print(color, std::string, ...);
	static void Print(std::string sMessage, ...);
	static void centerPrint(color eColor, const char* sMessage);
	static void Visible(bool);
};