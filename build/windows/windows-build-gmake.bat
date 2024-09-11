@echo off
pushd ..\..\
call build\windows\premake5.exe gmake2
popd
pause