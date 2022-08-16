#include "King.h"

King::King(Color color, bool alive, Position pos) : Piece(Type::King, color, alive, pos)
{

}

void King::printPiece()
{
    Piece::printPiece();
    cout << "Check : " << isInCheck << endl;
}
