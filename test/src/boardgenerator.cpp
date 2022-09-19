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
    chessBoard.clear();
    cout << "Lunghezza della configurazione : " << conf.itemsVector.size() << endl;
    int counters[int(Piece::Type::NTypes)] = { 0 };

    for(auto item: conf.itemsVector){
        if(item.live){
            Piece *piece = chessBoard.createPiece(item.type,item.color,item.pos);

            int &num = counters[int(piece->getType())];
            piece->setNumber(num);
            num++;

            chessBoard.pieceVector.push_back(piece);
            
        }
    }
}
void BoardGenerator::clear(){
    chessBoard.clear();
}


