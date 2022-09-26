/*
classe di test il cui compito è quello di simulare e verificare
determinate posizioni in una ChessBoard 
*/

#include "chessboard.h"
#include "piece.h"
#include "chessboardprinter.h"
#include "boardGenerator.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{

    Configuration conf = Configuration("C:/Users/Lucio/Desktop/Programmazione/Git/Chess/test/data/configurations.txt");
    conf.printConfiguration();
    BoardGenerator boardGenerator(conf);
    boardGenerator.chessBoard.printPieces();

    ChessBoardPrinter printer(boardGenerator.chessBoard);
    printer.setCurPiece(nullptr);
    printer.printChessBoardToStdout();

    boardGenerator.chessBoard.generateAllPos();
    boardGenerator.chessBoard.pieceVector[0]->printAccessiblePos();

    char tmp;
    std::cin >> tmp;

    return 0;
}