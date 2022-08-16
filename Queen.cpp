#include "Queen.h"

Queen::Queen(string s, bool color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Queen::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
