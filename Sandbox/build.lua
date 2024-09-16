project "Sandbox"
	location "."

	include "common.lua"

	includedirs {

		"%{IncludeDir.glfw}",
		"%{wks.location}/Vulture/src/Platform/Window"
	}

	links {

		"Vulture"
	}

	filter "configurations:*Static"
		links {

			"glfw"
		}
