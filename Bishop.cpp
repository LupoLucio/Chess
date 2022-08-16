#include "Bishop.h"

Bishop::Bishop(string s, bool color, bool alive, Position pos)
{
    name = s;
    isWhite = color;
    isAlive = alive;
    p = pos;
}

void Bishop::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
