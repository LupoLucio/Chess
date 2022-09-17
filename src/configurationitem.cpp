#include "configurationitem.h"

#include <iostream>
using namespace std;

ConfigurationItem::ConfigurationItem()
{

}

ConfigurationItem::ConfigurationItem(Piece::Type type_, Piece::Color col_, Position pos_)
{
    type = type_;
    color = col_;
    pos = pos_;
}

ConfigurationItem::~ConfigurationItem()
{
    
}

void ConfigurationItem::set(Piece::Type type_, Piece::Color col_, Position pos_)
{
    type = type_;
    color = col_;
    pos = pos_;
}

Piece::Type ConfigurationItem::getType()
{
    return type;
}

Piece::Color ConfigurationItem::getColor()
{
    return color;
}

Position ConfigurationItem::getPos()
{
    return pos;
}

void ConfigurationItem::print()
{
    cout << static_cast<int>(color) << " " << static_cast<int>(type)<< " " << live << " ";
    pos.printPosition();
}