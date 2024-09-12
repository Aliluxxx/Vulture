#include "vepch.h"

#include "ApplicationWindow.h"

namespace ve {

	Application::Application(const ApplicationSpecification& spec)
		: m_Specification(spec)

	{


	}

	Application::~Application() {


	}

	void Application::Close() {


	}

	void Application::Run() {

		VE_CORE_INFO("Hi from Run method");
	}

	const char* ApplicationCommandLineArgs::operator[](int index) const {

		VE_CORE_ASSERT(index < Count, "Array index out of bounds");
		return Args[index];
	}
}
