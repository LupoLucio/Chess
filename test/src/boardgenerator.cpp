#include "boardGenerator.h"

#include <iostream>
using namespace std;

BoardGenerator::BoardGenerator()
{
}
BoardGenerator::~BoardGenerator()
{
    clear();
}
void BoardGenerator::clear(){
    for(ChessBoard* chessBoard : chessBoards){
        chessBoard->clear();
    }
}
