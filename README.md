# VibeCasino
Simple C++ raylib demo: an example online-casino (slot machine) UI.

This repository contains a minimal C++ project using raylib that implements
a small slot-machine-style casino demo. It is intended as a starting point
for building a graphical casino app using raylib.

Build & Run
----------

1. Install dependencies (Ubuntu example):

```bash
sudo apt update
sudo apt install -y build-essential cmake pkg-config libraylib-dev
```

If `libraylib-dev` is not available on your distribution, follow the
raylib build instructions: https://github.com/raysan5/raylib

2. Build the project:

```bash
mkdir -p build && cd build
cmake ..
make -j
```

3. Run:

```bash
./vibecasino
```

Build with Makefile
-------------------

If you prefer `make` (the repository includes a `Makefile`) you can build and run directly from the repository root:

```bash
make
./vibecasino
```

Controls
- Left / Right: decrease / increase bet
- Space: Spin the slot machine

Notes
- This is a small demo and not a production-ready online casino.
- You can extend it by adding networking, more games, persistence, and
	better UI/graphics.
Using the bundled raylib submodule (Windows / offline builds)
-----------------------------------------------------------

This project can optionally build a bundled copy of raylib from a git
submodule. This is useful on Windows where a system package may not be
available. The repository includes a `.gitmodules` entry; to fetch the
submodule run:

```bash
git submodule update --init --recursive
```

Or add the submodule yourself if it's not present:

```bash
git submodule add https://github.com/raysan5/raylib.git external/raylib
git submodule update --init --recursive
```

After the submodule is present you can build with CMake as usual. On
Windows you may want to select the appropriate generator (Visual Studio
or MinGW):

```powershell
# Example for MSYS2/MinGW
mkdir build && cd build
cmake -G "MSYS Makefiles" ..
make
```

If neither pkg-config nor the submodule are available CMake will stop
and show instructions to add the submodule or install raylib on your
system.
