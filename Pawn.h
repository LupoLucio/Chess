#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

/*
Classe che definisce il pezzo King
*/
class Pawn : public Piece
{
public:
    string name;

    Pawn() = default;
    Pawn(string s, bool color, bool alive, Position pos);

    void printPiece();
};

#endif
