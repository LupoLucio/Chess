#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Knight : public Piece{

    public:
    string name;

    Knight()=default;
    Knight(string s,bool color,bool live,Position pos);

    void printPiece();




};

#endif