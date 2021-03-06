# megadrive-helloworld
An example program to make getting started with Sega Megadrive (aka Sega Genesis) development easier

The aim is to provide a very basic, working, self-contained project to serve as documentation for the Mega Drive/Genesis hardware and uses modern unpatched versions of common development tools

## Building the toolchain
1. install native development tools
  - on ubuntu or debian: `sudo apt-get install build-essential`
2. download the gnu binutils tarball ([last tested version here](http://ftp.gnu.org/gnu/binutils/binutils-2.25.tar.gz))
3. (almost) standard compilation:
  1. `tar -xzf binutils-*.tar.gz`
  2. `cd binutils-*`
  3. `./configure --target=m68k-none-elf`
  4. `make`
  5. `sudo make install` or copy the `./gas/as`, `./ld/ld`, `./binutils/objcopy` and `./binutils/objdump` binaries to a directory in your `PATH`

## Building the program
1. `make realclean all`
2. run the resulting `.bin` file in an emulator or a console

## Useful make targets
- `make` or `make all` builds the source code
- `make run` runs the flat binary in `dgen`
- `make clean` deletes any generated files except for the flat binary
- `make realclean` deletes the flat binary and the above
- `make dumpelf` disassembles the compiled ELF binary
- `make dumpbin` disassembles the compiled flat binary
- `make dumphex` dumps the compiled flat binary in hexadecimal form
