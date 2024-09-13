include "dependencies.lua"

workspace "Vulture-None"
	location "../../"

	defines {

		"VULTURE_HEADLESS",
		"VULTURE_NONE"
	}

	printf("OS: Windows")
	system "windows"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-DLL", "Release-DLL", "Dist-DLL" }
	platforms { "x86", "x64", "arm", "arm64" }
	filter { "platforms:x86" }
		architecture "x86"
	filter { "platforms:x64" }
		architecture "x86_64"
	filter { "platforms:arm" }
		architecture "ARM"
	filter { "platforms:arm64" }
		architecture "ARM64"

	filter {}

	flags { "MultiProcessorCompile" }
	startproject "Sandbox-None"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "../../Sandbox/build-none.lua"
	include "../../Vulture/build-none.lua"
