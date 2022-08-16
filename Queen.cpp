#include "Queen.h"

Queen::Queen(string s, bool color, bool live, Position pos)
{
    name = s;
    isWhite = color;
    isLive = live;
    p = pos;
}

void Queen::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isLive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")" << endl;
}
