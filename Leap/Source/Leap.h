#pragma once

#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define LEAP_API __declspec(dllexport)
#else
	#define LEAP_API __declspec(dllimport)
#endif
