#include "King.h"

King::King(string s, Color color, bool alive, Position pos) : Piece(Type::King, color, alive, pos)
{
    name = s;
}

void King::printPiece()
{
    cout << "Name : " << name << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Check : " << isInCheck << " Position : (" << m_pos.getX()
         << "," << m_pos.getY() << ")" << endl;
}
