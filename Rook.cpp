#include "Rook.h"

Rook::Rook(string s, Color color, bool alive, Position pos) : Piece(Type::Rook, color, alive, pos)
{
    name = s;
}

void Rook::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << p.getX() << "," << p.getY() << ")"
         << endl;
}
