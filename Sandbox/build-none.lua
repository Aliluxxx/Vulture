project "Sandbox-none"
	location "."

	include "common.lua"

	includedirs {

		"%{IncludeDir.spdlog}"
	}

	links {

		"Vulture-None"
	}
