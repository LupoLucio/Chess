#include "configurationitem.h"

ConfigurationItem::ConfigurationItem()
{

}

ConfigurationItem::ConfigurationItem(Piece::Type type,Position pos)
{
    type = type;
    pos = pos;
}

void ConfigurationItem::set(Piece::Type type,Position pos){
    type = type;
    pos = pos;
}

Piece::Type ConfigurationItem::getType(){
    return type;
}

Position ConfigurationItem::getPos(){
    return pos;
}