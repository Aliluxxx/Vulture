defines {

	"VULTURE_HEADLESS"
}

flags { "MultiProcessorCompile" }
startproject "Sandbox-Headless"

outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
config = "%{cfg.buildcfg}"
arch = "%{cfg.architecture}"
OS = "%{cfg.system}"
sruntime = "Off"
