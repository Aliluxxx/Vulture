kind "ConsoleApp"
language "C++"
cppdialect "C++20"
targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

files {

	"**.lua",
	"src/*",
	"src/**.h", "src/**.cpp", "src/**.inl",
	"%{wks.location}/%{prj.name}/resources/**"
}

includedirs {

	"src",
	"%{wks.location}/Vulture/src"
}

-- Windows
filter "system:windows"
	defines {

		"VULTURE_PLATFORM_WINDOWS",
		"_CRT_SECURE_NO_WARNINGS"
	}

-- Linux
filter "system:linux"
	defines {

		"VULTURE_PLATFORM_LINUX"
	}

-- MacOSX
filter "system:macosx"
	defines {

		"VULTURE_PLATFORM_MACOSX"
	}
	
-- Static
filter "configurations:*Static"
	staticruntime "On"
	defines "VULTURE_STATIC"

-- Shared
filter "configurations:*DLL or *Shared"
	staticruntime "Off"

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

filter {}

-- Post build commands
postbuildcommands {

	("{MKDIR} ../bin/" .. outputdir .. "/%{prj.name}/resources"),
	("{COPYDIR} %{wks.location}/Sandbox/resources ../bin/" .. outputdir .. "/%{prj.name}/resources")
}
