#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
/*
Classe che definisce il pezzo King
*/
class Bishop : public Piece{

    public:
    string name;

    Bishop()=default;
    Bishop(string s,bool color,bool live,Position pos);

    void printPiece();



};

#endif