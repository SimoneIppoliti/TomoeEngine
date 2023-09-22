#pragma once

#ifdef TOMOE_PLATFORM_WINDOWS
	#ifdef TOMOE_BUILD_DLL
		#define TOMOE_ENGINE_API __declspec(dllexport)
	#else
		#define TOMOE_ENGINE_API __declspec(dllimport)
	#endif
#else
		#error Tomoe Engine only supports Windows.
#endif