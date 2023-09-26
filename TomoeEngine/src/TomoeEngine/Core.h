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

#define BIT(x) (1 << x)