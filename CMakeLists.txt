cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

add_executable(Chess ${CHESS_SOURCES})
