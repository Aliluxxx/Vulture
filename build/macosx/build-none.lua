include "../dependencies.lua"

workspace "Vulture-None"
	location "../../"

	printf("OS: MacOSX")
	system "macosx"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
	platforms { "universal" }
	filter { "platforms:universal" }
		architecture "universal"

	filter {}

	include "../settings-none.lua"
	include "../projects-none.lua"
