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

// Math
#include "Vulture/Math/Color.h"
#include "Vulture/Math/Math.h"
#include "Vulture/Math/Matrix3.h"
#include "Vulture/Math/Matrix4.h"
#include "Vulture/Math/Vector2.h"
#include "Vulture/Math/Vector3.h"
#include "Vulture/Math/Vector4.h"
