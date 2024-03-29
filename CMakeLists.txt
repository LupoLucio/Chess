cmake_minimum_required(VERSION 3.5)

project(Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include include/pieces src/pieces test/include test/src)

# Headers are listed here so they show up in IDE (tested on Qt Creator 5)
# They are generally not needed for compilation because they are found automatically

set(CHESS_HEADERS
    include/pieces/bishop.h
    include/pieces/king.h
    include/pieces/knight.h
    include/pieces/pawn.h
    include/pieces/piece.h
    include/pieces/queen.h
    include/pieces/rook.h
    include/chessboard.h
    include/chessboardprinter.h
    include/position.h
    include/configuration.h
    include/configurationitem.h)

set(CHESS_SOURCES
    src/pieces/bishop.cpp
    src/pieces/king.cpp
    src/pieces/knight.cpp
    src/pieces/pawn.cpp
    src/pieces/piece.cpp
    src/pieces/queen.cpp
    src/pieces/rook.cpp
    src/chessboard.cpp
    src/chessboard2.cpp
    src/chessboardprinter.cpp
    src/position.cpp
    src/configurationitem.cpp
    src/configuration.cpp)

set(PROGRAM_SOURCES  
    src/main.cpp)

set(TEST_HEADERS
    test/include/boardgenerator.h)

set(TEST_SOURCES
    test/src/testposition.cpp
    test/src/boardgenerator.cpp)

# Aggiungere file configurazione
# test/data/configurations.txt

add_executable(Chess ${CHESS_SOURCES} ${PROGRAM_SOURCES})
add_executable(Test ${CHESS_SOURCES} ${TEST_SOURCES})
