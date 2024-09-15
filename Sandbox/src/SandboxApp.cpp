#include <Vulture.h>

// ---------- Entry point ----------
#include <Vulture/Core/EntryPoint.h>
// ---------------------------------

#include "SandboxLayer.h"

class Sandbox : public ve::Application {

public:

	Sandbox(const ve::ApplicationSpecification& spec)
		: ve::Application(spec)

	{

		PushLayer(ve::CreateRef<SandboxLayer>());
	}

	~Sandbox() {}
};

ve::Application* ve::CreateApplication(ve::ApplicationCommandLineArgs args) {

	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = ".";
	spec.CommandLineArgs = args;
#ifdef VULTURE_HEADLESS
	spec.SleepDuration = ve::Milliseconds(1);
#endif

	return new Sandbox(spec);
}
