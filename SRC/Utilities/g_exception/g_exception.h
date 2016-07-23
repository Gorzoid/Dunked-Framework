#pragma once

class g_exception
{
public:
	static long __stdcall unhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo);
	static void traceLastFunction(const char*, const char*);
};