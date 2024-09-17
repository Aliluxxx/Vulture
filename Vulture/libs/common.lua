-- Debug
filter "configurations:Debug*"
	runtime "Debug"
	symbols "On"
	optimize "Off"
	targetsuffix "-d"

-- Release
filter "configurations:Release*"
	runtime "Release"
	symbols "On"
	optimize "On"
	targetsuffix "-r"

-- Dist
filter "configurations:Dist*"
	runtime "Release"
	symbols "Off"
	optimize "On"
	targetsuffix ""
