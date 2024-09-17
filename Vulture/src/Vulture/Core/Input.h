#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Math/Vector2.h"
#include "Vulture/Core/KeyCodes.h"
#include "Vulture/Core/MouseCodes.h"

namespace ve {

	class VULTURE_API Input {

	public:

		static bool IsKeyPressed(KeyCode keycode);
		static bool IsMouseButtonPressed(MouseCode button);
		static ve::Vector2i GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
