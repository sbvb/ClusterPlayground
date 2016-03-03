#include "connection.h"
#include "distance.h"

#include <QPainter>
#include <qdebug.h>

Connection::Connection(QPointF *start, QPointF *end, QGraphicsItem *parent):CustomItem(parent)
{
    m_start = start;
    m_end = end;
    setZValue(-1);
}

QRectF Connection::boundingRect() const
{
    return QRectF(*m_start,*m_end);
}

void Connection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawLine(*m_start,*m_end);
}

std::string Connection::getName(){
    return std::string("Connection");
}

double Connection::getLength(){
    return distance(*m_start,*m_end);
}

bool Connection::isClickable(){
    return false;
}

