#include "Rook.h"

Rook::Rook(string s, bool color, bool live, Position pos)
{
    name = s;
    isWhite = color;
    isLive = live;
    p = pos;
}

void Rook::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isLive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")" << endl;
}
