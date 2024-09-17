#include "vepch.h"

#include <GLFW/glfw3.h>

#include "Vulture/Events/ApplicationEvent.h"
#include "Vulture/Events/KeyEvent.h"
#include "Vulture/Events/MouseEvent.h"

#include "GLFWWindow.h"

namespace ve {

	static int g_glfwInit = 0;

	static void GLFWErrorCallback(int error, const char* msg) {

		VE_CORE_ERROR("GLFW Error ({0}): {1}", error, msg);
	}

	Ref<Window> Window::Create(const WindowProps& prop) {

		return CreateRef<GLFWWindow>(prop);
	}

	GLFWWindow::GLFWWindow(const WindowProps& prop)
		: m_Handle(nullptr)

	{

		// Initialize GLFW
		if (g_glfwInit == 0) {

			int result = glfwInit();
			VE_CORE_ASSERT(result == GLFW_TRUE, "Failed to initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		g_glfwInit++;

		m_Data.Title = prop.Title;
		m_Data.Width = prop.Width;
		m_Data.Height = prop.Height;

		if (prop.Style != Style::None) {

			glfwWindowHint(GLFW_DECORATED, prop.Style & Style::Titlebar ? GLFW_TRUE : GLFW_FALSE);
			glfwWindowHint(GLFW_RESIZABLE, prop.Style & Style::Resize ? GLFW_TRUE : GLFW_FALSE);
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		// Create the window
		m_Handle = glfwCreateWindow(prop.Width, prop.Height, prop.Title.c_str(), nullptr, nullptr);
		VE_CORE_ASSERT(m_Handle != nullptr, "Failed to create window");
		glfwSetWindowUserPointer(m_Handle, &m_Data);

		// Set the window to the center of the screen
		int x, y, width, height;
		glfwGetMonitorWorkarea(glfwGetPrimaryMonitor(), &x, &y, &width, &height);
		glfwSetWindowPos(m_Handle, width / 2 - prop.Width / 2, height / 2 - prop.Height / 2);

		// Set callbacks

		glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* window) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* window, int width, int height) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowPosCallback(m_Handle, [](GLFWwindow* window, int x, int y) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			WindowMovedEvent event(x, y);
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Handle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action) {

				case GLFW_PRESS: {

					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}

				case GLFW_REPEAT: {

					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}

				case GLFW_RELEASE: {

					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Handle, [](GLFWwindow* window, int button, int action, int mods) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			switch (action) {

				case GLFW_PRESS: {

					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}

				case GLFW_RELEASE: {

					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Handle, [](GLFWwindow* window, double x_offset, double y_offset) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseScrolledEvent event((float)x_offset, (float)y_offset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Handle, [](GLFWwindow* window, double x, double y) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			MouseMovedEvent event((float)x, (float)y);
			data.EventCallback(event);
		});

		glfwSetCharCallback(m_Handle, [](GLFWwindow* window, unsigned int codepoint) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			KeyTypedEvent event(codepoint);
			data.EventCallback(event);
		});

		glfwSetWindowFocusCallback(m_Handle, [](GLFWwindow* window, int focused) {

			WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));

			if (focused == GLFW_TRUE) {

				WindowFocusEvent event;
				data.EventCallback(event);
			}

			else if (focused == GLFW_FALSE) {

				WindowLostFocusEvent event;
				data.EventCallback(event);
			}
		});
	}

	GLFWWindow::~GLFWWindow() {

		// Destroy the window
		glfwDestroyWindow(m_Handle);

		// Terminate GLFW
		if (g_glfwInit == 0)
			glfwTerminate();
		else
			g_glfwInit--;
	}

	void GLFWWindow::OnUpdate() {

		glfwPollEvents();
	}

	std::string GLFWWindow::GetTitle() const {

		return std::string(glfwGetWindowTitle(m_Handle));
	}

	void GLFWWindow::SetTitle(const std::string& title) {

		glfwSetWindowTitle(m_Handle, title.c_str());
	}

	Uint32 GLFWWindow::GetWidth() const {

		int width, height;
		glfwGetWindowSize(m_Handle, &width, &height);
		return width;
	}

	void GLFWWindow::SetWidth(Uint32 width) {

		int oldWidth, oldHeight;
		glfwGetWindowSize(m_Handle, &oldWidth, &oldHeight);
		glfwSetWindowSize(m_Handle, width, oldHeight);
	}

	Uint32 GLFWWindow::GetHeight() const {

		int width, height;
		glfwGetWindowSize(m_Handle, &width, &height);
		return height;
	}

	void GLFWWindow::SetHeight(Uint32 height) {

		int oldWidth, oldHeight;
		glfwGetWindowSize(m_Handle, &oldWidth, &oldHeight);
		glfwSetWindowSize(m_Handle, oldWidth, height);
	}

	Int32 GLFWWindow::GetX() const {

		int x, y;
		glfwGetWindowPos(m_Handle, &x, &y);
		return x;
	}

	void GLFWWindow::SetX(Int32 x) {

		int oldX, oldY;
		glfwGetWindowPos(m_Handle, &oldX, &oldY);
		glfwSetWindowPos(m_Handle, x, oldY);
	}

	Int32 GLFWWindow::GetY() const {

		int x, y;
		glfwGetWindowPos(m_Handle, &x, &y);
		return y;
	}

	void GLFWWindow::SetY(Int32 y) {

		int oldX, oldY;
		glfwGetWindowPos(m_Handle, &oldX, &oldY);
		glfwSetWindowPos(m_Handle, oldX, y);
	}

	void GLFWWindow::SetEventCallback(const EventCallbackFn& callback) {

		m_Data.EventCallback = callback;
	}

	void GLFWWindow::SetVSync(bool enabled) {

		m_Data.VSync = enabled;
	}

	bool GLFWWindow::IsVSync() const {

		return m_Data.VSync;
	}

	void GLFWWindow::SetMouseCursorVisible(bool visible) {

		glfwSetInputMode(m_Handle, GLFW_CURSOR, visible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN);
	}

	void GLFWWindow::SetMouseCursorGrabbed(bool grabbed) {

		glfwSetInputMode(m_Handle, GLFW_CURSOR, grabbed ? GLFW_CURSOR_CAPTURED : GLFW_CURSOR_NORMAL);
	}

	void GLFWWindow::SetMouseCursorDisabled(bool disable) {

		glfwSetInputMode(m_Handle, GLFW_CURSOR, disable ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
	}

	void* GLFWWindow::GetNativeWindow() const {

		return m_Handle;
	}
}
