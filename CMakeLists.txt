cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Headers are listed here so they show up in IDE (tested on Qt Creator 5)
# They are generally not needed for compilation because they are found automatically
set(CHESS_HEADERS
    Bishop.h
    ChessBoard.h
    King.h
    Knight.h
    Pawn.h
    Piece.h
    Position.h
    Queen.h
    Rook.h)

set(CHESS_SOURCES
    Bishop.cpp
    ChessBoard.cpp
    ChessBoard2.cpp
    King.cpp
    Knight.cpp
    Pawn.cpp
    Piece.cpp
    Position.cpp
    Queen.cpp
    Rook.cpp
    main.cpp)

add_executable(Chess ${CHESS_HEADERS} ${CHESS_SOURCES})
