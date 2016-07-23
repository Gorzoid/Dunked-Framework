#pragma once

/*
****************************
      Dunked-Framework
****************************
*/

static const char* BUILDDATE = __DATE__;
static const char* BUILDTIME = __TIME__;

#define _CRT_SECURE_NO_WARNINGS
#define VC_EXTRALEAN

using byte = unsigned char;

// Windows Includes
#include <Windows.h>
#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <process.h>
#include <string>

// Namespace
namespace Dunked
{
	extern unsigned int __stdcall Init(void*);
	extern void DeInit();
}

// Local Includes

// Utilities
#include "Utilities/g_utillist.h"