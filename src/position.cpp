// Class to describe a generic position on the Chess Board

#include "position.h"

#include <iostream>

using namespace std;

Position::Position(int newx, int newy)
{
    x = newx;
    y = newy;
}
void Position::printPosition()
{
    cout << "Position is (" << x << "," << y << ")" << endl;
}

int Position::getX() const
{
    return x;
}

int Position::getY() const
{
    return y;
}

void Position::setX(int newx)
{
    x = newx;
}

void Position::setY(int newy)
{
    y = newy;
}

bool Position::operator==(const Position &position) const
{
    return x == position.getX() && y == position.getY();
}

bool Position::isInChessBoard()
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}

Position operator+(const Position &left, const Position &right)
{
    return Position(left.getX() + right.getX(), left.getY() + right.getY());
}
