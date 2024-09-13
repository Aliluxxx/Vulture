#include <Vulture.h>

// ---------- Entry point ----------
#include <Vulture/Core/EntryPoint.h>
// ---------------------------------

class Sandbox : public ve::Application {

public:

	Sandbox(const ve::ApplicationSpecification& spec)
		: ve::Application(spec)

	{


	}

	~Sandbox() {


	}
};

ve::Application* ve::CreateApplication(ve::ApplicationCommandLineArgs args) {

	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = ".";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
