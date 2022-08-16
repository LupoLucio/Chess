#include "Bishop.h"

Bishop::Bishop(string s, Color color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void Bishop::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
