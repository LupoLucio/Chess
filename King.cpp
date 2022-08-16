#include "King.h"

King::King(string s, bool color, bool live, Position pos)
{
    name = s;
    isWhite = color;
    isLive = live;
    p = pos;
}

void King::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isLive
         << " Virgin : " << isVirgin << " Check : " << isInCheck << " Position : (" << p.getX()
         << "," << p.getY() << ")" << endl;
}
