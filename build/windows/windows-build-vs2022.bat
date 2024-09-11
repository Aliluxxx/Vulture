@echo off
pushd ..\..\
call build\windows\premake5.exe vs2022
popd
pause