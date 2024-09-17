#include "vepch.h"

#include <GLFW/glfw3.h>

#include "Vulture/Core/ApplicationWindow.h"

#include "Vulture/Core/Input.h"

namespace ve {

	bool Input::IsKeyPressed(KeyCode keycode) {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(MouseCode button) {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	ve::Vector2i Input::GetMousePosition() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return (float)xpos;
	}

	float Input::GetMouseY() {

		auto window = static_cast<GLFWwindow*>(Application::GetWindow()->GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return (float)xpos;
	}
}
