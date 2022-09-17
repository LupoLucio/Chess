#ifndef CONFIGURATIONITEM_H
#define CONFIGURATIONITEM_H

#include "piece.h"

class ConfigurationItem
{
public:
    Piece::Type type;
    Piece::Color color;
    Position pos;

    ConfigurationItem();
    ConfigurationItem(Piece::Type type_, Piece::Color col_, Position pos_);
    ~ConfigurationItem();

    void print();
    void set(Piece::Type type_, Piece::Color col_, Position pos_);
    
    Piece::Type getType();
    Piece::Color getColor();
    Position getPos();

};

#endif