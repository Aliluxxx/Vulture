project "Sandbox"
	location "."

	include "common.lua"

	includedirs {

		"%{IncludeDir.spdlog}"
	}

	links {

		"Vulture"
	}
