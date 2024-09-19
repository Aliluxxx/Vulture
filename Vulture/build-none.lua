project "Vulture-None"
	location "."

	include "common.lua"

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
