#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
/*
Classe che definisce il pezzo King
*/
class Knight : public Piece
{
public:
    Knight(Color color, bool alive, Position pos);
};

#endif
