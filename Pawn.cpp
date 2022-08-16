#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(string s, bool color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Pawn::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
