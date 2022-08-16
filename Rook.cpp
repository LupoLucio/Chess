#include "Rook.h"

Rook::Rook(string s, bool color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Rook::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
