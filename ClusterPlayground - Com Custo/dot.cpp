#include "dot.h"

Dot::Dot(double x, double y, double dotRadius, Qt::GlobalColor color, QGraphicsItem *parent) : CustomItem(parent)
{
    m_brush = QBrush(color);
    m_pos = QPointF(x,y);
    m_radius = dotRadius;
    m_isCenter = false;
}

Dot::Dot(QPointF pos, double dotRadius, Qt::GlobalColor color, QGraphicsItem *parent) : CustomItem(parent)
{
    m_brush = QBrush(color);
    m_pos = pos;
    m_radius = dotRadius;
    m_isCenter = false;
}

QRectF Dot::boundingRect() const
{
    return QRectF(m_pos-QPointF(m_radius,m_radius),
                  m_pos+QPointF(m_radius,m_radius));
}

void Dot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(m_brush);
    painter->drawEllipse(m_pos,m_radius,m_radius);
}

void Dot::makeCenter(){
    m_isCenter = true;
}

void Dot::setPos(QPointF pos){
    m_pos = pos;
}

void Dot::setPos(double x, double y){
    m_pos = QPointF(x,y);
}

void Dot::setConnection(Connection *connection){
    m_connection = connection;
}

std::string Dot::getName(){
    return std::string("Dot");
}

QPointF Dot::getPos(){
    return m_pos;
}

QPointF *Dot::getPosPointer(){
    return &m_pos;
}

Connection *Dot::getConnection(){
    return m_connection;
}

bool Dot::isCenter(){
    return m_isCenter;
}

bool Dot::isClickable(){
    return true;
}

