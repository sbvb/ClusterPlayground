#include "customitem.h"

CustomItem::CustomItem(QGraphicsItem *parent):QGraphicsItem(parent){m_clickeable = false;}

std::string CustomItem::getName(){
    return std::string("CustomItem");
}

void CustomItem::setClickeable(bool clickeable){
    m_clickeable = clickeable;
}

bool CustomItem::isClickeable(){
    return m_clickeable;
}
