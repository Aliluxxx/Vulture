#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Window.h"

struct GLFWwindow;

namespace ve {

	class VULTURE_API GLFWWindow : public Window {

	public:

		GLFWWindow(const WindowProps& prop);
		~GLFWWindow();

		virtual void OnUpdate() override;

		virtual std::string GetTitle() const override;
		virtual void SetTitle(const std::string& title) override;
		virtual Uint32 GetWidth() const override;
		virtual void SetWidth(Uint32 width) override;
		virtual Uint32 GetHeight() const override;
		virtual void SetHeight(Uint32 height) override;
		virtual Int32 GetX() const override;
		virtual void SetX(Int32 x) override;
		virtual Int32 GetY() const override;
		virtual void SetY(Int32 y) override;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;
		virtual void SetMouseCursorVisible(bool visible) override;
		virtual void SetMouseCursorGrabbed(bool grabbed) override;
		virtual void SetMouseCursorDisabled(bool disable) override;

		virtual void* GetNativeWindow() const override;

	private:

		GLFWwindow* m_Handle;

		struct WindowData {

			std::string Title;
			Uint32 Width = 0;
			Uint32 Height = 0;
			bool VSync = false;
			EventCallbackFn EventCallback;

		} m_Data;
	};
}
