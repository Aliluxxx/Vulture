#pragma once

#include <string>
#include <filesystem>

#include "Vulture/Core/Base.h"
#include "Vulture/Core/LayerStack.h"
#include "Vulture/Events/ApplicationEvent.h"
#include "Vulture/Core/Window.h"
#include "Vulture/Core/Timer.h"

#ifdef VULTURE_PLATFORM_WINDOWS
	int main(int argc, char** argv);
#else
	int main();
#endif

namespace ve {

	struct VULTURE_API ApplicationCommandLineArgs {

		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const;
	};

	struct VULTURE_API ApplicationSpecification {

		std::string Name = "Vulture App";
		std::filesystem::path WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class VULTURE_API Application {

	public:

		Application(const ApplicationSpecification& spec);
		virtual ~Application();

		void OnEvent(Event& e);

		static void PushLayer(Ref<Layer> layer);
		static void PushOverlay(Ref<Layer> overlay);

		static void Close();

		inline static const Ref<Window> GetWindow() {

			return s_Instance->m_Window;
		}

		inline static const ApplicationSpecification& GetSpecification() {

			return s_Instance->m_Specification;
		}

	private:

		void Run();

		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);

		static Application* s_Instance;

		ApplicationSpecification m_Specification;
		Ref<Window> m_Window;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		Timer m_Timer;

#ifdef VULTURE_PLATFORM_WINDOWS
		friend int ::main(int argc, char** argv);
#else
		friend int ::main();
#endif
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}
