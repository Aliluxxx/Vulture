#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Math/Vector2.h"
#include "Vulture/Core/KeyCodes.h"
#include "Vulture/Core/MouseCodes.h"

namespace ve {

	class VULTURE_API Input {

	public:

		static bool IsKeyPressed(KeyCode keycode) {

			return s_Instance->IsKeyPressedImpl(keycode);
		}

		static bool IsMouseButtonPressed(MouseCode button) {

			return s_Instance->IsMouseButtonPressedImpl(button);
		}

		static ve::Vector2i GetMousePosition() {

			return s_Instance->GetMousePositionImpl();
		}

		static float GetMouseX() {

			return s_Instance->GetMouseXImpl();
		}

		static float GetMouseY() {

			return s_Instance->GetMouseYImpl();
		}

	protected:

		static Scope<Input> s_Instance;

		virtual bool IsKeyPressedImpl(KeyCode keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
		virtual ve::Vector2i GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	};
}
