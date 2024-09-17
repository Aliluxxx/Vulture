include "../dependencies.lua"

workspace "Vulture-Headless"
	location "../../"

	printf("OS: MacOSX")
	system "macosx"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
	platforms { "universal" }
	filter { "platforms:universal" }
		architecture "universal"

	filter {}

	include "../settings-headless.lua"
	include "../projects-headless.lua"
