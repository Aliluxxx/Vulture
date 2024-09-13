#pragma once

#ifdef VULTURE_HEADLESS
	#include "Platform/Headless/VultureHeadless.h"
#else
	#include "Platform/Window/VultureWindow.h"
#endif

// Application
#include "Vulture/Core/Application.h"

// Time
#include "Vulture/Core/Sleep.h"
#include "Vulture/Core/Time.h"
#include "Vulture/Core/Timer.h"
