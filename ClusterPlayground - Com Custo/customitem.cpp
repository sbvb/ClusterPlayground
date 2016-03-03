#include "customitem.h"

CustomItem::CustomItem(QGraphicsItem *parent):QGraphicsItem(parent){}

std::string CustomItem::getName(){
    return std::string("CustomItem");
}

bool CustomItem::isClickable(){
    return false;
}
