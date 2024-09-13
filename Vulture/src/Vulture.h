#pragma once

#ifdef VULTURE_HEADLESS
	#include "Platform/Headless/VultureHeadless.h"
#else
	#include "Platform/Window/VultureWindow.h"
#endif

#include "Vulture/Core/Application.h"
