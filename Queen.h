#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Queen : public Piece
{
public:
    string name;

    Queen(string s, bool color, bool alive, Position pos);

    void printPiece();
};

#endif
