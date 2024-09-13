include "dependencies.lua"

workspace "Vulture-Headless"
	location "../../"

	defines {

		"VULTURE_HEADLESS"
	}

	printf("OS: MacOSX")
	system "macosx"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
	platforms { "universal" }
	filter { "platforms:universal" }
		architecture "universal"

	filter {}

	flags { "MultiProcessorCompile" }
	startproject "Sandbox-Headless"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "../../Sandbox/build-headless.lua"
	include "../../Vulture/build-headless.lua"
