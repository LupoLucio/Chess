// Header file of Position.cpp
#ifndef POSITION_H
#define POSITION_H
#include <iostream>

using namespace std;

/*
Classe che definisce il concetto di posizione in una ChessBoard
*/
class Position {

public:
    // coordinate
    int x, y;

    // costruttori
    Position() = default;
    Position(int newx, int newy);
    // stampa
    void printPosition();
    // getters
    int getX() const;
    int getY() const;
    // setters
    void setX(int newx);
    void setY(int newy);

    bool operator==(const Position& position) const;
};

#endif
