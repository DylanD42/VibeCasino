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
