@echo off
setlocal

set PS4_PORT=9021
set PS4_HOST=ps4
set "PS4_PAYLOAD="

:argparse
if "%1"=="" goto runcmd
if "%1" == "-h" (
  set PS4_HOST=%2
  shift
  shift
  goto :argparse
)
if "%1" == "-p" (
  set PS4_PORT=%2
  shift
  shift
  goto :argparse
)
set PS4_PAYLOAD=%1
shift
goto :argparse

:runcmd

if "%PS4_PAYLOAD%"=="" (
  echo usage: %0 [-h HOST] [-p PORT] PAYLOAD_PATH
  exit /b 1
)

type %PS4_PAYLOAD% | plink.exe -raw -P %PS4_PORT% %PS4_HOST%
