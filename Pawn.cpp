#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(string s, Color color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Pawn::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
