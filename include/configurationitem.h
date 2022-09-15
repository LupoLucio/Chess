#ifndef CONFIGURATIONITEM_H
#define CONFIGURATIONITEM_H

#include "piece.h"

class ConfigurationItem
{
public:
    Piece::Type type;
    Position pos;

    ConfigurationItem();
    ConfigurationItem(Piece::Type type,Position pos);
    ~ConfigurationItem();

    void printItem();
    void set(Piece::Type type,Position pos);
    Piece::Type getType();
    Position getPos();

};

#endif