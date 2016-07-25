#pragma once

class g_interfacegrabber
{
	typedef void* (*CreateInterfaceFn)(const char* p1, int* p2);
public:
	static void* getAddress(const char* chModule, const char* chInterface);
	static void dump();
};