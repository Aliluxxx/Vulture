project "Vulture"
	location "."

	include "common.lua"

	files {

		"src/Platform/Window/**.h",
		"src/Platform/Backend/**.h"
	}

	includedirs {

		"src",
		"%{IncludeDir.spdlog}"
	}

-- Post build commands
filter "configurations:*DLL or *Shared"
	postbuildcommands {

		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}
