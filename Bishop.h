#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Bishop : public Piece
{
public:
    string name;

    Bishop(string s, bool color, bool alive, Position pos);

    void printPiece();
};

#endif
