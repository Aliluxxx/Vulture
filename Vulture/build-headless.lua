project "Vulture-Headless"
	location "."

	include "common.lua"

	defines {

		"VULTURE_HEADLESS",
		"VULTURE_NONE"
	}

	files {

		"src/Platform/Headless/**",
		"src/Platform/Backend/**"
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

		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox-Headless"),
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox-Headless")
	}
