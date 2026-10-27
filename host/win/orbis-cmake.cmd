@echo off
setlocal

set PS4_PAYLOAD_SDK=%~dp0..

set CMAKE_GENERATOR=Ninja
set CMAKE_TOOLCHAIN_FILE=%PS4_PAYLOAD_SDK%\toolchain\orbis.cmake
set CMAKE_MAKE_PROGRAM=%PS4_PAYLOAD_SDK%\win\ninja.exe

cmake %*
