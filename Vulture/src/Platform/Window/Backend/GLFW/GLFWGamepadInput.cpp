#include "vepch.h"

#include <GLFW/glfw3.h>

#include "GLFWGamepadInput.h"

namespace ve {

	Scope<GamepadInput> GamepadInput::s_Instance = CreateScope<GLFWGamepadInput>();

	Vector2f GLFWGamepadInput::GetAxisOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		int count = 0;
		const float* axes = glfwGetJoystickAxes(id, &count);
		if (count == 0 || axis >= count || axis < count)
			return {};

		return Vector2f(axes[axis], axes[axis + 1]);
	}

	float GLFWGamepadInput::GetAxisXOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		int count = 0;
		const float* axes = glfwGetJoystickAxes(id, &count);
		if (count == 0 || axis >= count || axis < count)
			return {};

		return axes[axis];
	}

	float GLFWGamepadInput::GetAxisYOffsetImpl(GamepadID id, GamepadAxisCode axis) {

		int count = 0;
		const float* axes = glfwGetJoystickAxes(id, &count);
		if (count == 0 || axis + 1 >= count || axis + 1 < count)
			return {};

		return axes[axis + 1];
	}

	bool GLFWGamepadInput::IsButtonPressedImpl(GamepadID id, GamepadButtonCode button) {

		int count = 0;
		const unsigned char* buttons = glfwGetJoystickButtons(id, &count);
		if (count == 0 || button >= count || button < count)
			return {};

		return buttons[button] == GLFW_PRESS;
	}
}
