# Chess

A small test program to play Chess game.

## Compile

### Using CMake
- Install CMake ([link](https://cmake.org/ "CMake home page"))
- Go to project directory
- Create a build directory
```
mkdir build
cd build
```
- Configure cmake and build, for example:
```
cmake ..
cmake --build . -t Chess
```
- The executable will be in `build/` subdirectory, named `Chess` or `Chess.exe`

### Using g++

```
g++ -o Chess main.cpp Position.cpp Piece.cpp ChessBoard.cpp ChessBoard2.cpp King.cpp Queen.cpp Rook.cpp Bishop.cpp Knight.cpp Pawn.cpp
```
