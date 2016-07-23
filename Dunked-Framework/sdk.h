#pragma once

/*
	Dunked-Framework
*/

static const char* BUILDDATE = __DATE__;
static const char* BUILDTIME = __TIME__;

#define _CRT_SECURE_NO_WARNINGS
#define	VC_EXTRALEAN

using byte = unsigned char;

// Windows Includes
#include <Windows.h>
#include <process.h>