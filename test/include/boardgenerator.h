#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include "chessboard.h"
#include "configuration.h"
/*
classe che definisce un oggetto capace di genrare una ChessBoard
e riempirla 
*/

class BoardGenerator{

public:
    ChessBoard chessBoard;

    BoardGenerator();
    BoardGenerator(Configuration conf);
    ~BoardGenerator();

    void clear();

    // metodo che ritorna se la chessBoard è in una configurazione valida
    bool isChessBoardValid();

    // ritorna un oggetto ChessBoard derivandola da conf
    ChessBoard* generate(Configuration conf);

};


#endif