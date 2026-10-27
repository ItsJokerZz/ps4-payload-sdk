# ps4-payload-sdk
This is an SDK for developing payloads targeted at exploited PS4s. ELF loaders
known to work include:
- https://github.com/shahrilnet/remote_lua_loader
- https://github.com/ps4-payload-dev/elfldr

## Prerequisites
On Debian-flavored operating systems, you can invoke the following command to
install dependencies used by the SDK.
```console
john@localhost:ps4-payload-dev/sdk$ sudo apt-get update && sudo apt-get upgrade # optional
john@localhost:ps4-payload-dev/sdk$ sudo apt-get install bash wget # required
john@localhost:ps4-payload-dev/sdk$ wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && sudo ./llvm.sh 23 # required
john@localhost:ps4-payload-dev/sdk$ sudo apt-get install llvm-23 llvm-23-dev lld-23 # required
john@localhost:ps4-payload-dev/sdk$ sudo apt-get install socat cmake meson pkg-config python3 python3-pyelftools # optional
```
The SDK itself builds with LLVM 15 or newer. The libc++ step in [Building the SDK](#building-the-sdk)
builds LLVM 23, and libc++ 23 needs a host compiler that is Clang 21 or newer.

If you are using Fedora, you can install dependencies as follows (tested with version 41):
```console
john@localhost:ps4-payload-dev/sdk$ sudo dnf install bash llvm-devel clang lld wget # required
john@localhost:ps4-payload-dev/sdk$ sudo dnf install socat cmake meson pkg-config python3 python3-pyelftools # optional
```

If you are using macOS, you can install them using the [Homebrew Package Manager][macos-brew] (tested with macOS Sequoia):
```console
john@localhost:ps4-payload-dev/sdk$ brew install llvm lld wget # required
john@localhost:ps4-payload-dev/sdk$ export LLVM_CONFIG=/opt/homebrew/opt/llvm/bin/llvm-config # required
john@localhost:ps4-payload-dev/sdk$ brew install socat cmake meson python && pip3 install pyelftools # optional
```

## Quick-start
You can download a binary distribution of the SDK from [the latest release page][latest-rel],
then install it to your local storage, e.g,
```console
john@localhost:tmp$ wget https://github.com/ps4-payload-dev/sdk/releases/latest/download/ps4-payload-sdk.zip
john@localhost:tmp$ sudo unzip -d /opt ps4-payload-sdk.zip
```
Assuming you have all the prerequisites and you are on a POSIX system,
the binary distribution should work regardless of CPU architecture, e.g., x86_64, aarch64.


## Usage
```console
john@localhost:ps4-payload-dev/sdk$ export PS4_PAYLOAD_SDK=/opt/ps4-payload-sdk
john@localhost:ps4-payload-dev/sdk$ make -C samples/hello_stdio
john@localhost:ps4-payload-dev/sdk$ export PS4_HOST=ps4; export PS4_PORT=9021
john@localhost:ps4-payload-dev/sdk$ make -C samples/hello_stdio test
```

## Building the SDK
```console
john@localhost:ps4-payload-dev/sdk$ sudo make DESTDIR=/opt/ps4-payload-sdk install
john@localhost:ps4-payload-dev/sdk$ export PS4_PAYLOAD_SDK=/opt/ps4-payload-sdk
john@localhost:ps4-payload-dev/sdk$ sudo -E ./libcxx.sh # fetch, build, and install libcxx
```

## Adding new SCE Libs
If you have decrypted sprx files that you would like to interact with, you can
build stubs for them as follows:
```console
john@localhost:ps4-payload-dev/sdk$ sudo apt-get install wget python3 python3-pyelftools
john@localhost:ps4-payload-dev/sdk$ ln -s /path/to/sprx/libSceXYZ.sprx sce_stubs/libSceXYZ.sprx
john@localhost:ps4-payload-dev/sdk$ make -C sce_stubs stubs
john@localhost:ps4-payload-dev/sdk$ sudo make DESTDIR=/opt/ps4-payload-sdk install
```

## Working firmwares
Offsets for all listed versions are included in the SDK.

<details>
<summary>Firmware offsets</summary>

- [x] 3.50
- [x] 3.55
- [x] 3.70
- [x] 4.00 and 4.01
- [x] 4.05
- [x] 4.06
- [x] 4.07
- [x] 4.50 and 4.55
- [x] 4.70
- [x] 4.71 to 4.74
- [x] 5.00 and 5.01
- [x] 5.03 to 5.07
- [x] 5.50
- [x] 5.53
- [x] 5.55 and 5.56
- [x] 6.00 and 6.02
- [x] 6.20
- [x] 6.50 and 6.51
- [x] 6.70 to 6.72
- [x] 7.00
- [x] 7.01
- [x] 7.02
- [x] 7.50, 7.51, and 7.55
- [x] 8.00 to 8.03
- [x] 8.50 and 8.52
- [x] 9.00
- [x] 9.03 and 9.04
- [x] 9.50, 9.51, and 9.60
- [x] 10.00 and 10.01
- [x] 10.50, 10.70 and 10.71
- [x] 11.00
- [x] 11.02
- [x] 11.50 and 11.52
- [x] 12.00 and 12.02
- [x] 12.50 and 12.52
- [x] 13.00
- [x] 13.02 and 13.04
- [x] 13.50
- [x] 13.52
- [x] 14.00

</details>

## Reporting Bugs
If you encounter problems with the SDK, please [file a github issue][issues].
If you plan on sending pull requests which affect more than a few lines of code,
please file an issue before you start to work on you changes. This will allow us
to discuss the solution properly before you commit time and effort.

## License
Files in the folder include/freebsd-9.3 are licenced under BSD licences.
Unless otherwhise explicitly stated inside a file, the rest are licensed under
the GPLv3+.

[issues]: https://github.com/ps4-payload-dev/sdk/issues/new
[latest-rel]: https://github.com/ps4-payload-dev/sdk/releases/latest
[macos-brew]: https://brew.sh
