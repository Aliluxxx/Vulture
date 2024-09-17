#include "vepch.h"

#include "Vulture/Core/Input.h"

namespace ve {

	bool Input::IsKeyPressed(KeyCode keycode) {

		return false;
	}

	bool Input::IsMouseButtonPressed(MouseCode button) {

		return false;
	}

	ve::Vector2i Input::GetMousePosition() {

		return { 0.0f, 0.0f };
	}

	float Input::GetMouseX() {

		return 0.0f;
	}

	float Input::GetMouseY() {

		return 0.0f;
	}
}
