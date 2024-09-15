project "Sandbox"
	location "."

	include "common.lua"

	includedirs {

		"%{wks.location}/Vulture/src/Platform/Window"
	}

	links {

		"Vulture"
	}
