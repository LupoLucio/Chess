#include "King.h"

King::King(string s, Color color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void King::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Check : " << isInCheck << " Position : (" << p.getX()
         << "," << p.getY() << ")" << endl;
}
