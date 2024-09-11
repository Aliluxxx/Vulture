include "dependencies.lua"

workspace "Vulture"

	-- Windows
	if os.host() == "windows" then
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

	-- Linux
	elseif os.host() == "linux" then
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

	-- MacOSX
	elseif os.host() == "macosx" then
		printf("OS: MacOSX")
		system "macosx"
		configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
		platforms { "universal" }
		filter { "platforms:universal" }
			architecture "universal"
	end

	filter {}

	flags { "MultiProcessorCompile" }
	startproject "Sandbox"

	outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
	config = "%{cfg.buildcfg}"
	arch = "%{cfg.architecture}"
	OS = "%{cfg.system}"

	include "Sandbox"
	include "Vulture"
