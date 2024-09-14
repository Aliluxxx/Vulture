#pragma once

#include <string>
#include <filesystem>

#include "Vulture/Core/Base.h"
#include "Vulture/Core/LayerStack.h"
#include "Vulture/Core/Timer.h"

#ifdef VULTURE_PLATFORM_WINDOWS
	int main(int argc, char** argv);
#else
	int main();
#endif

namespace ve {

	struct ApplicationCommandLineArgs {

		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const;
	};

	struct ApplicationSpecification {

		std::string Name = "Vulture Headless App";
		std::filesystem::path WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
		Time SleepDuration;
	};

	class VULTURE_API Application {

	public:

		Application(const ApplicationSpecification& spec);
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Ref<Layer> layer);
		void PushOverlay(Ref<Layer> overlay);

		void Close();

		inline const ApplicationSpecification& GetSpecification() const {

			return m_Specification;
		}

	private:

		void Run();

		static Application* s_Instance;

		ApplicationSpecification m_Specification;

		bool m_Running = true;
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
