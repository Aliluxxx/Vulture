#include "vepch.h"

#include "ApplicationWindow.h"

namespace ve {

	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& spec)
		: m_Specification(spec)

	{

		VE_CORE_ASSERT(!s_Instance, "Application already exists");
		s_Instance = this;

		WindowProps prop = {};
		prop.Style = ve::Style::Default;
		m_Window = Window::Create(prop);
		m_Window->SetEventCallback(VE_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {

		m_LayerStack.Clear();
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(VE_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(VE_BIND_EVENT_FN(Application::OnWindowResized));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {

			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Ref<Layer> layer) {

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Ref<Layer> overlay) {

		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Close() {

		m_Running = false;
	}

	void Application::Run() {

		while (m_Running) {

			float time = m_Timer.GetElapsedTime().AsSeconds();
			Time m_Timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			m_Window->OnUpdate();

			if (m_Minimized)
				continue;

			for (Ref<Layer> layer : m_LayerStack)
				layer->OnUpdate(m_Timestep);

			for (Ref<Layer> layer : m_LayerStack)
				layer->OnImGuiRender();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {

		m_Running = false;
		return false;
	}

	bool Application::OnWindowResized(WindowResizeEvent& e) {

		if (e.GetWidth() == 0 || e.GetHeight() == 0) {

			m_Minimized = true;
			return false;
		}

		else {

			m_Minimized = false;
		}

		return false;
	}

	const char* ApplicationCommandLineArgs::operator[](int index) const {

		VE_CORE_ASSERT(index < Count, "Array index out of bounds");
		return Args[index];
	}
}
