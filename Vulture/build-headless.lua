project "Vulture-Headless"
	location "."

	include "common.lua"

	defines {

		"VULTURE_HEADLESS",
		"VULTURE_NONE"
	}

	files {

		"src/Platform/Headless/**",

		"src/Platform/Backend/Vulkan/**"
	}

	filter "system:windows"
		files {

			"src/Platform/Backend/DirectX11/**",
			"src/Platform/Backend/DirectX12/**",
			"src/Platform/Backend/OpenGL/**"
		}

	filter "system:linux"

	filter "system:macosx"
		files {

			"src/Platform/Backend/Metal/**"
		}

-- Post build commands
filter "configurations:*DLL or *Shared"
	postbuildcommands {

		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox-Headless"),
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox-Headless")
	}
