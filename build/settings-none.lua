defines {

	"VULTURE_HEADLESS",
	"VULTURE_NONE"
}

flags { "MultiProcessorCompile" }
startproject "Sandbox-None"

outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
config = "%{cfg.buildcfg}"
arch = "%{cfg.architecture}"
OS = "%{cfg.system}"
sruntime = "On"
