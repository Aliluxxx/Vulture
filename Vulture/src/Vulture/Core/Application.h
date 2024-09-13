#pragma once

#ifdef VULTURE_HEADLESS
	#include "Platform/Headless/Vulture/Core/ApplicationHeadless.h"
#else
#include "Platform/Window/Vulture/Core/ApplicationWindow.h"
#endif
