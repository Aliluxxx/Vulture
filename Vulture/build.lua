project "Vulture"
	location "."

	include "common.lua"

	files {

		"src/Platform/Window/*",
		"src/Platform/Window/Vulture/**",

		"src/Platform/Backend/Vulkan"
	}

	includedirs {

		"src/Platform/Window"
	}

	filter "system:windows"
		files {

			"src/Platform/Window/Backend/GLFW/**",

			"src/Platform/Backend/DirectX11/**",
			"src/Platform/Backend/DirectX12/**",
			"src/Platform/Backend/OpenGL/**"
		}

	filter "system:linux"
		files {

			--"src/Platform/Window/Backend/Linux/**"
			"src/Platform/Window/Backend/GLFW/**"
		}

	filter "system:macosx"
		files {

			--"src/Platform/Window/Backend/MacOSX/**",
			"src/Platform/Window/Backend/GLFW/**",

			"src/Platform/Backend/Metal/**"
		}


-- Post build commands
filter "configurations:*DLL or *Shared"
	postbuildcommands {

		("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
		("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}
