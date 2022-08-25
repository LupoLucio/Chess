#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
/*
Classe che definisce il pezzo King
*/
class Rook : public Piece
{
public:
    Rook(Color color, bool alive, Position pos);
};

#endif
