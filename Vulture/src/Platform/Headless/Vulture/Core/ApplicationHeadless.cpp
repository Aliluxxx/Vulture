#include "vepch.h"

#include "ApplicationHeadless.h"

namespace ve {

	Application::Application(const ApplicationSpecification& spec)
		: m_Specification(spec)

	{

#ifdef VULTURE_PLATFORM_WINDOWS
		system(("TITLE " + m_Specification.Name).c_str());
#endif
	}

	Application::~Application() {


	}

	void Application::Close() {


	}

	void Application::Run() {

		VE_CORE_INFO("Hi from Run-Headless method");
	}

	const char* ApplicationCommandLineArgs::operator[](int index) const {

		VE_CORE_ASSERT(index < Count, "Array index out of bounds");
		return Args[index];
	}
}
