#pragma once

#include <functional>

#include "Vulture/Core/Base.h"
#include "Vulture/Events/Event.h"

namespace ve {

	using WindowStyle = Uint32;
	namespace Style {

		enum {

			Titlebar = BIT(0),
			Resize = BIT(1),
			Close = BIT(2)
		};

		const WindowStyle None = 0;
		const WindowStyle Default = Titlebar | Resize | Close;
	}

	struct VULTURE_API WindowProps {

		std::string Title;
		Uint32 Width;
		Uint32 Height;
		WindowStyle Style;

		WindowProps(const std::string& title = "Vulture Window",
			Uint32 width = 1280,
			Uint32 height = 720,
			WindowStyle style = ve::Style::Default)
			: Title(title), Width(width), Height(height), Style(style)

		{}
	};

	class VULTURE_API Window {

	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual std::string GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;
		virtual Uint32 GetWidth() const = 0;
		virtual void SetWidth(Uint32 width) = 0;
		virtual Uint32 GetHeight() const = 0;
		virtual void SetHeight(Uint32 height) = 0;
		virtual Int32 GetX() const = 0;
		virtual void SetX(Int32 x) = 0;
		virtual Int32 GetY() const = 0;
		virtual void SetY(Int32 y) = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Ref<Window> Create(const WindowProps& props = WindowProps());
	};
}
