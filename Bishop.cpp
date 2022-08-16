#include "Bishop.h"

Bishop::Bishop(string s, bool color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Bishop::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
