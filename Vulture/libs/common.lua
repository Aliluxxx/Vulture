-- Debug
filter "configurations:Debug*"
	runtime "Debug"
	symbols "On"
	optimize "Off"

-- Release
filter "configurations:Release*"
	runtime "Release"
	symbols "On"
	optimize "On"

-- Dist
filter "configurations:Dist*"
	runtime "Release"
	symbols "Off"
	optimize "On"

filter { "Debug*", "kind:StaticLib" }
	targetsuffix "-d"

filter { "Release*", "kind:StaticLib" }
	targetsuffix "-r"

filter { "Dist*", "kind:StaticLib" }
	targetsuffix ""

filter {}
