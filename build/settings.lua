flags { "MultiProcessorCompile" }
startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.platform}"
config = "%{cfg.buildcfg}"
arch = "%{cfg.architecture}"
OS = "%{cfg.system}"
sruntime = "On"
