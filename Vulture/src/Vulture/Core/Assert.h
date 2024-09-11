#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Log.h"

#ifdef VE_ENABLE_ASSERTS
	#define VE_ASSERT(x, ...)          if(!(x)) { VE_ERROR     ("Assertion Failed: {0}", __VA_ARGS__); VE_DEBUGBREAK(); }
	#ifdef VULTURE_ENGINE
		#define VE_CORE_ASSERT(x, ...) if(!(x)) { VE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); VE_DEBUGBREAK(); }
	#endif
#else
	#define VE_ASSERT(x, ...) 0
	#ifdef VULTURE_ENGINE
		#define VE_CORE_ASSERT(x, ...) 0
	#endif
#endif
