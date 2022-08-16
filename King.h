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

    King() = default;
    King(string s, bool color, bool live, Position pos);

    void printPiece();
};

#endif
