#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
/*
Classe che definisce il pezzo King
*/
class Bishop : public Piece
{
public:
    Bishop(Color color, bool alive, Position pos);
};

#endif
