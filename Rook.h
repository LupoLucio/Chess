#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Rook : public Piece
{
public:
    string name;

    Rook() = default;
    Rook(string s, bool color, bool alive, Position pos);

    void printPiece();
};

#endif
