# Vulture
A simple engine that will be used as backend for a stupid project like a minecraft clone or something

## Download instructions

To clone the repository use the following git command:
`git clone --recursive https://github.com/Aliluxxx/Vulture Vulture`.

If the repository was cloned non-recursively previously, type `git submodule update --init` to clone the necessary submodules.

## Build instructions
You can run the script files inside the `build` folder or execute manually the commands down below. This project uses [premake5](https://premake.github.io/) to generate build files
#### NOTE: This project is mainly supported on Windows machines, so do not expect this project to run on other operating systems, because it may or may not work

### Windows
- To create project files for Visual Studio 2022 (recommended), use: `build\windows\premake5.exe vs2022`
- To create project files for gmake, use: `build\windows\premake5.exe gmake2`

### Linux
- To create project files for Codelite, use: `./build/linux/premake5 codelite`
- To create project files for gmake, use: `./build/linux/premake5 gmake2`

### MacOSX
- To create project files for XCode, use: `./build/macosx/premake5 xcode4`
- To create project files for gmake, use: `./build/macosx/premake5 gmake2`
