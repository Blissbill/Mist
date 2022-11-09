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

#ifdef MT_DEBUG
	#define MT_ENABLE_ASSERTS
#endif

#ifdef MT_ENABLE_ASSERTS
	#define MT_ASSERT(x, ...) { if (!(x)) { MT_ERROR("Assertion Filed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MT_CORE_ASSERT(x, ...) { if (!(x)) { MT_CORE_ERROR("Assertion Filed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MT_ASSERT(x, ...)
	#define MT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)