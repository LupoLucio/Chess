#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include "chessboard.h"
#include "configuration.h"
/*
classe che definisce un oggetto capace di genrare una o piu' ChessBoard
e riempirla 
*/

class BoardGenerator{

public:
    std::vector<ChessBoard*> chessBoards;

    BoardGenerator();
    ~BoardGenerator();

    void clear();

    // ritorna un oggetto ChessBoard derivandola da conf
    ChessBoard* generate(Configuration conf);

};


#endif