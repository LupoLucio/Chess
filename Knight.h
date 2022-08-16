#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Knight : public Piece
{
public:
    string name;

    Knight(string s, bool color, bool alive, Position pos);

    void printPiece();
};

#endif
