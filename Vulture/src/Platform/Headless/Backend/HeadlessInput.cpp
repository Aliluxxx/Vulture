#include "vepch.h"

#include "HeadlessInput.h"

namespace ve {

	Scope<Input> Input::s_Instance = CreateScope<HeadlessInput>();

	bool HeadlessInput::IsKeyPressedImpl(KeyCode keycode) {

		return false;
	}

	bool HeadlessInput::IsMouseButtonPressedImpl(MouseCode button) {

		return false;
	}

	ve::Vector2i HeadlessInput::GetMousePositionImpl() {

		return { 0.0f, 0.0f };
	}

	float HeadlessInput::GetMouseXImpl() {

		return 0.0f;
	}

	float HeadlessInput::GetMouseYImpl() {

		return 0.0f;
	}
}
