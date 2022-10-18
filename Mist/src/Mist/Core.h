#pragma once

#ifdef MT_PLATFORM_WINDOWS
	#ifdef MT_BUILD_DLL
		#define MIST_API __declspec(dllexport)
	#else
		#define MIST_API __declspec(dllimport)
	#endif // MT_BUILD_DLL
#else
	#error Mist only supports on Windows
#endif