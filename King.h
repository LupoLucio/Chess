#ifndef KING_H
#define KING_H
#include "Piece.h"

/*
Classe che definisce il pezzo King
*/
class King : public Piece
{
public:
    bool isInCheck = 0;

    King(Color color, bool alive, Position pos);

    void printPiece() override;
};

#endif
