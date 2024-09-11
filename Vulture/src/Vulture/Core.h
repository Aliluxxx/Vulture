#pragma once

#ifndef VULTURE_STATIC
	#ifdef VULTURE_PLATFORM_WINDOWS
		#ifdef VULTURE_BUILD_DLL
			#define VULTURE_API __declspec(dllexport)
		#else
			#define VULTURE_API __declspec(dllimport)
		#endif
	#else
		#error Vulture only supports Windows!
	#endif
#else
	#define VULTURE_API
#endif

void VULTURE_API print();
