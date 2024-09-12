#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Application.h"

extern ve::Application* ve::CreateApplication(ApplicationCommandLineArgs args);

#ifdef VULTURE_PLATFORM_WINDOWS

int main(int argc, char** argv) {

	ve::Log::Init();

	ve::Application* app = ve::CreateApplication({ argc, argv });
	app->Run();
	delete app;

	return 0;
}

#else

int VULTURE_API main() {

	ve::Log::Init();

	ve::Application app = ve::CreateApplication({ 0, nullptr });
	app->Run();
	delete app;

	return 0;
}

#endif
