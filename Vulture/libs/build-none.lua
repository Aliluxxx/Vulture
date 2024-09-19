project "nativefiledialog"
	location "."
	kind "StaticLib"
	staticruntime ("" .. sruntime .. "")
	language "C"
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/libs")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/libs")

	files {

		"nativefiledialog-extended/src/**.h"
	}

	includedirs {

		"nativefiledialog-extended/src/include"
	}

	filter "system:windows"
		defines "_CRT_SECURE_NO_WARNINGS"
		files "nativefiledialog-extended/src/nfd_win.cpp"

	filter "system:linux"
		files "nativefiledialog-extended/src/nfd_portal.cpp"

	filter "system:macosx"
		files "nativefiledialog-extended/src/nfd_cocoa.m"

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
