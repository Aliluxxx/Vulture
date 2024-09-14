include "../dependencies.lua"

workspace "Vulture"
	location "../../"

	printf("OS: Linux")
	system "linux"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
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
	startproject "Sandbox"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "../projects.lua"
