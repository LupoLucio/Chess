#ifndef KING_H
#define KING_H
#include "Piece.h"

/*
Classe che definisce il pezzo King
*/
class King : public Piece
{
public:
    string name;
    bool isInCheck = 0;

    King(string s, Color color, bool alive, Position pos);

    void printPiece();
};

#endif
