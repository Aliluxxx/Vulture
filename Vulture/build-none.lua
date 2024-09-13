project "Vulture-None"
	location "."

	include "common.lua"

	defines {

		"VULTURE_HEADLESS",
		"VULTURE_NONE"
	}

	files {

		"src/Platform/Headless/**"
	}

	removefiles {

		"src/Vulture/Renderer/**"
	}

	includedirs {

		"src",
		"%{IncludeDir.spdlog}"
	}

-- Post build commands
filter "configurations:*DLL or *Shared"
	postbuildcommands {

		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox-None"),
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox-None")
	}
