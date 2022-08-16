#include "King.h"

King::King(string s, bool color, bool alive, Position pos) : Piece(color, alive, pos)
{
    name = s;
}

void King::printPiece()
{
    cout << "Name : " << name << " Color : " << isWhite << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Check : " << isInCheck << " Position : (" << p.getX()
         << "," << p.getY() << ")" << endl;
}
