include "../dependencies.lua"

workspace "Vulture"
	location "../../"

	printf("OS: MacOSX")
	system "macosx"
	configurations { "Debug-Static", "Release-Static", "Dist-Static", "Debug-Shared", "Release-Shared", "Dist-Shared" }
	platforms { "universal" }
	filter { "platforms:universal" }
		architecture "universal"

	filter {}

	include "../settings.lua"
	include "../projects.lua"
