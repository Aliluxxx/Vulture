# Vulture
A simple engine that will be used as backend for a stupid project like a minecraft clone or something

## Download instructions

To clone the repository use the following git command:
`git clone --recursive https://github.com/Aliluxxx/Vulture Vulture`.

If the repository was cloned non-recursively previously, type `git submodule update --init` to clone the necessary submodules.

## Build instructions
To generate project files, you can run the script files inside the `build` folder or execute manually the commands down below. This project uses [premake5](https://premake.github.io/) to generate configuration files.
There are 3 possible configurations that can be generated at the moment:

### Default
To use all the available tools inside the engine. It will create a window to draw to screen the result of rendering operations. This mode is guaranteed to work only for Windows OS. It may or may not work on other operating systems.

#### Windows
Inside `build\windows`, run the command:
- `premake5.exe --file=build.lua vs2022` or run the script `build-vs2022.bat` to generate Visual Studio 2022 projects
- `premake5.exe --file=build.lua gmake2` or run the script `build-gmake.bat` to generate Makefiles projects

#### Linux
Inside `build/linux`, run the command:
- `./premake5 --file=build.lua codelite` or run the script `build-codelite.sh` to generate Codelite projects
- `./premake5 --file=build.lua gmake2` or run the script `build-gmake.sh` to generate Makefiles projects

#### MacOSX
Inside `build/macosx`, run the command:
- `./premake5 --file=build.lua xcode4` or run the script `build-xcode4.sh` to generate Xcode projects
- `./premake5 --file=build.lua gmake2` or run the script `build-gmake.sh` to generate Makefiles projects

### Headless
Similar to the default configuration except it will not create a window, so only off-screen rendering will be available. This mode is guaranteed to work only for Windows OS. It may or may not work on other operating systems.

#### Windows
Inside `build\windows`, run the command:
- `premake5.exe --file=build-headless.lua vs2022` or run the script `build-headless-vs2022.bat` to generate Visual Studio 2022 projects
- `premake5.exe --file=build-headless.lua gmake2` or run the script `build-headless-gmake.bat` to generate Makefiles projects

#### Linux
Inside `build/linux`, run the command:
- `./premake5 --file=build-headless.lua codelite` or run the script `build-headless-codelite.sh` to generate Codelite projects
- `./premake5 --file=build-headless.lua gmake2` or run the script `build-headless-gmake.sh` to generate Makefiles projects

#### MacOSX
Inside `build/macosx`, run the command:
- `./premake5 --file=build-headless.lua xcode4` or run the script `build-headless-xcode4.sh` to generate Xcode projects
- `./premake5 --file=build-headless.lua gmake2` or run the script `build-headless-gmake.sh` to generate Makefiles projects

### None
Similar to the headless configuration except it completely strips out the project the rendering-related code (only modules like audio, filesystem and network will be available). This mode is guaranteed to work for every operating system

#### Windows
Inside `build\windows`, run the command:
- `premake5.exe --file=build-none.lua vs2022` or run the script `build-none-vs2022.bat` to generate Visual Studio 2022 projects
- `premake5.exe --file=build-none.lua gmake2` or run the script `build-none-gmake.bat` to generate Makefiles projects

#### Linux
Inside `build/linux`, run the command:
- `./premake5 --file=build-none.lua codelite` or run the script `build-none-codelite.sh` to generate Codelite projects
- `./premake5 --file=build-none.lua gmake2` or run the script `build-none-gmake.sh` to generate Makefiles projects

#### MacOSX
Inside `build/macosx`, run the command:
- `./premake5 --file=build-none.lua xcode4` or run the script `build-none-xcode4.sh` to generate Xcode projects
- `./premake5 --file=build-none.lua gmake2` or run the script `build-none-gmake.sh` to generate Makefiles projects
