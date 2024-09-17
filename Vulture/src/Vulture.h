#pragma once

#ifdef VULTURE_HEADLESS
	#include "Platform/Headless/VultureHeadless.h"
#else
	#include "Platform/Window/VultureWindow.h"
#endif

// Application
#include "Vulture/Core/Application.h"
#include "Vulture/Core/Layer.h"
#include "Vulture/Core/LayerStack.h"

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

// File
#include "Vulture/Core/FileSystem.h"
#include "Vulture/Core/FileDialog.h"
#include "Vulture/Core/InputStream.h"
#include "Vulture/Core/FileInputStream.h"
#include "Vulture/Core/MemoryInputStream.h"

// Input
#include "Vulture/Core/Input.h"

// Event codes
#include "Vulture/Events/ApplicationEvent.h"
#include "Vulture/Events/KeyEvent.h"
#include "Vulture/Events/MouseEvent.h"
#include "Vulture/Core/KeyCodes.h"
#include "Vulture/Core/MouseCodes.h"
#include "Vulture/Core/GamepadCodes.h"
