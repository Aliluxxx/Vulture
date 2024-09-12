include "dependencies.lua"

workspace "Vulture-Headless"
	location "../../"

	defines {

		"VULTURE_HEADLESS"
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
	startproject "Sandbox-Headless"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "../../Sandbox/build-headless.lua"
	include "../../Vulture/build-headless.lua"
