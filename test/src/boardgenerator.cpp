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
BoardGenerator::BoardGenerator(Configuration conf)
{
    
}
void BoardGenerator::clear(){
    chessBoard.clear();
}


