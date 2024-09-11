project "Vulture"
	printf("Project: Vulture")
	language "C++"
	cppdialect "C++20"
	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files {

		"src/**.h", "src/**.cpp", "src/**.inl",
		"%{wks.location}/%{prj.name}/resources/**"
	}

	includedirs {

		"src",
		"%{IncludeDir.spdlog}"
	}

	defines "VULTURE_ENGINE"

	-- Windows
	filter "system:windows"
		pchheader "vepch.h"
		pchsource "src/vepch.cpp"
		defines {

			"VULTURE_PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

	-- Linux
	filter "system:linux"
		pchheader "%{wks.location}/%{prj.name}/src/vepch.h"
		removefiles "src/vepch.cpp"
		defines {

			"VULTURE_PLATFORM_LINUX"
		}

	-- MacOSX
	filter "system:macosx"
		pchheader "%{wks.location}/%{prj.name}/src/vepch.h"
		removefiles "src/vepch.cpp"
		defines {

			"VULTURE_PLATFORM_MACOSX"
		}

	-- Debug
	filter "configurations:Debug*"
		defines "VULTURE_DEBUG"
		runtime "Debug"
		symbols "On"

	-- Release
	filter "configurations:Release*"
		defines "VULTURE_RELEASE"
		runtime "Release"
		symbols "On"
		optimize "On"

	-- Dist
	filter "configurations:Dist*"
		defines "VULTURE_DIST"
		runtime "Release"
		optimize "On"

	-- Static
	filter "configurations:*Static"
		kind "StaticLib"
		staticruntime "On"
		defines "VULTURE_STATIC"

	-- Shared
	filter "configurations:*DLL or *Shared"
		kind "SharedLib"
		staticruntime "Off"

	filter "configurations:*DLL"
		defines "VULTURE_BUILD_DLL"

	filter "configurations:*Shared"
		defines "VULTURE_BUILD_SHARED"

	filter { "Debug*", "kind:StaticLib" }
		targetsuffix "-s-d"

	filter { "Debug*", "kind:SharedLib" }
		targetsuffix "-d"

	filter { "Release*", "kind:StaticLib" }
		targetsuffix "-s-r"

	filter { "Release*", "kind:SharedLib" }
		targetsuffix "-r"

	filter { "Dist*", "kind:StaticLib" }
		targetsuffix "-s"

	filter { "Dist*", "kind:SharedLib" }
		targetsuffix ""

	-- Post build commands
	filter "configurations:*DLL or *Shared"
		postbuildcommands {

			("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
