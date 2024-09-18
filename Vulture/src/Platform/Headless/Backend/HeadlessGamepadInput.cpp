#include "vepch.h"

#include "HeadlessGamepadInput.h"

namespace ve {

	Scope<GamepadInput> GamepadInput::s_Instance = CreateScope<HeadlessGamepadInput>();

	Vector2f HeadlessGamepadInput::GetAxisOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		return {};
	}

	float HeadlessGamepadInput::GetAxisXOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		return 0.0f;
	}

	float HeadlessGamepadInput::GetAxisYOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		return 0.0f;
	}

	bool HeadlessGamepadInput::IsButtonPressedImpl(GamepadID id, GamepadButtonCode button) {

		return false;
	}
}
