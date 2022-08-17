#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Queen : public Piece
{
public:
    Queen(Color color, bool alive, Position pos);
};

#endif
