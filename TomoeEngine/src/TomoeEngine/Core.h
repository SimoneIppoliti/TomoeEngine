#pragma once

#ifdef TOMOE_PLATFORM_WINDOWS
	#ifdef TOMOE_BUILD_DLL
		#define TOMOE_API __declspec(dllexport)
	#else
		#define TOMOE_API __declspec(dllimport)
	#endif
#else
		#error Tomoe Engine only supports Windows.
#endif

#ifdef TOMOE_ENABLE_ASSERTS
	#define TOMOE_ASSERT(x, ...) { if (!(x)) { TOMOE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TOMOE_CORE_ASSERT(x, ...) { if (!(x)) { TOMOE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TOMOE_ASSERT(x, ...)
	#define TOMOE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TOMOE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)