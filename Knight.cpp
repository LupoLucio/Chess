#include "Knight.h"

Knight::Knight(string s, bool color, bool live, Position pos)
{
    name = s;
    isWhite = color;
    isLive = live;
    p = pos;
}

void Knight::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isLive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")" << endl;
}
