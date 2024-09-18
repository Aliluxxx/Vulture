#include "vepch.h"

#include <GLFW/glfw3.h>

#include "Vulture/Core/ApplicationWindow.h"

#include "GLFWInput.h"

namespace ve {

	Scope<Input> Input::s_Instance = CreateScope<GLFWInput>();

	bool GLFWInput::IsKeyPressedImpl(KeyCode keycode) {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool GLFWInput::IsMouseButtonPressedImpl(MouseCode button) {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	ve::Vector2i GLFWInput::GetMousePositionImpl() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float GLFWInput::GetMouseXImpl() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return (float)xpos;
	}

	float GLFWInput::GetMouseYImpl() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return (float)xpos;
	}
}
