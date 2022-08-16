#include "Piece.h"

Piece::Piece(bool color, bool live, Position pos)
{
    isWhite = color;
    isLive = live;
    p = pos;
}
void Piece::move(Position newP)
{
    p = newP;
}
Position Piece::getPosition()
{
    return p;
}

void Piece::printPiece()
{
}

void Piece::printControlledPos()
{
    cout << "controlledPos are : " << endl;
    for (int i = 0; i < controlledPos.size(); i++)
    {
        controlledPos[i].printPosition();
    }
}

void Piece::printAccessiblePos()
{
    cout << "AccessiblePos are : " << endl;
    for (int i = 0; i < accessiblePos.size(); i++)
    {
        accessiblePos[i].printPosition();
    }
}
void Piece::printAllPos()
{
    cout << "All positions are : " << endl;
    printControlledPos();
    printAccessiblePos();
}

bool Piece::operator==(Piece* piece)
{
    return p == piece->p && isWhite == piece->isWhite;
}

bool Piece::isOpposite(Piece* piece)
{
    return isWhite != piece->isWhite;
}

void Piece::setPosition(Position pos)
{
    p = pos;
}
