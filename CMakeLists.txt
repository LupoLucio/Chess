cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Headers are listed here so they show up in IDE (tested on Qt Creator 5)
# They are generally not needed for compilation because they are found automatically
set(CHESS_HEADERS
    bishop.h
    chessboard.h
    chessboardprinter.h
    king.h
    knight.h
    pawn.h
    piece.h
    position.h
    queen.h
    rook.h)

set(CHESS_SOURCES
    bishop.cpp
    chessboard.cpp
    chessboard2.cpp
    chessboardprinter.cpp
    king.cpp
    knight.cpp
    pawn.cpp
    piece.cpp
    position.cpp
    queen.cpp
    rook.cpp
    main.cpp)

add_executable(Chess ${CHESS_HEADERS} ${CHESS_SOURCES})
