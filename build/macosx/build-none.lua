include "../dependencies.lua"

workspace "Vulture-None"
	location "../../"

	defines {

		"VULTURE_HEADLESS",
		"VULTURE_NONE"
	}

	printf("OS: MacOSX")
	system "macosx"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
	platforms { "universal" }
	filter { "platforms:universal" }
		architecture "universal"

	filter {}

	flags { "MultiProcessorCompile" }
	startproject "Sandbox-None"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "../projects-none.lua"
