#include "Knight.h"

Knight::Knight(string s, Color color, bool alive, Position pos) : Piece(Type::Knight, color, alive, pos)
{
    name = s;
}

void Knight::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
