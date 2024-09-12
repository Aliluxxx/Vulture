project "Sandbox-Headless"
	location "."

	include "common.lua"

	includedirs {

		"%{IncludeDir.spdlog}"
	}

	links {

		"Vulture-Headless"
	}

