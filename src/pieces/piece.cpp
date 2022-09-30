#include "piece.h"

#include <iostream>
using namespace std;

Piece::Piece(Type type, Color color, bool alive, Position pos)
{
    m_color = color;
    m_type = type;
    isAlive = alive;
    m_pos = pos;
}
void Piece::move(const Position &newPos)
{
    m_pos = newPos;
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

void Piece::printPiece()
{
    cout << "Name : " << getTypeName(getType()) << " " << getNumber()
         << " Color : " << getColorName(getColor()) << " Live : " << isAlive
         << " Virgin : " << isVirgin << " Position : (" << m_pos.getX() << "," << m_pos.getY()
         << ")" << endl;
}

bool Piece::operator==(const Piece& other) const
{
    return m_pos == other.m_pos && m_color == other.m_color && m_type == other.m_type;
}

bool Piece::isOppositeColor(Piece *piece)
{
    return m_color != piece->m_color;
}

Position Piece::getPosition()
{
    return m_pos;
}
void Piece::setPosition(Position pos)
{
    m_pos = pos;
}

string Piece::getColorName(Color c)
{
    return c == Color::White ? "White" : "Black";
}

string Piece::getTypeName(Type t)
{
    const char *arr[int(Type::NTypes) + 1] = { "King", "Queen", "Rook", "Bishop",
                                               "Knight",  "Pawn", "NTypes" };

    int idx = int(t);
    if (idx < 0 || idx > int(Type::NTypes))
        idx = int(Type::NTypes);

    return arr[idx];
}

static const char shortName_arr[int(Piece::Type::NTypes)] = {
    'K', // King
    'q', // Queen
    'r', // Rook
    'b', // Bishop
    'k', // Knight
    'p'  // Pawn
};

char Piece::getTypeShortName(Type t)
{
    

    int idx = int(t);
    if (idx < 0 || idx > int(Type::NTypes))
        idx = int(Type::NTypes);

    return shortName_arr[idx];
}

Piece::Type Piece::parseTypeShortName(char shortName)
{
    for(int type = 0; type < int(Type::NTypes); type++)
    {
        if(shortName_arr[type] == shortName)
        {
            return Piece::Type(type);
        }
    }

    return Piece::Type::NTypes;
}
