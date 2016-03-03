#include <sstream>

#include "text.h"

Text::Text(QPointF position, double width, double heigth, const char *fixed_text, QGraphicsItem *parent) : CustomItem(parent)
{
    m_position = position;
    m_width = width;
    m_heigth = heigth;
    m_total_cost = 0;
    m_fixed_text = fixed_text;
    setZValue(-1);
}

Text::Text(double x, double y, double width, double heigth, const char *fixed_text, QGraphicsItem *parent) : CustomItem(parent)
{
    m_position = QPointF(x,y);
    m_width = width;
    m_heigth = heigth;
    m_total_cost = 0;
    m_fixed_text = fixed_text;
    setZValue(-1);
}

QRectF Text::boundingRect() const
{
    return QRectF(m_position,QPointF(m_width,m_heigth) + m_position);
}

void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    std::ostringstream sstring;
    sstring << m_fixed_text << m_total_cost;
    const char *output_string = sstring.str().c_str();

    painter->drawText(m_position,QString(output_string));
}

void Text::setTotalCost(double total_cost){
    m_total_cost = total_cost;
}

std::string Text::getName(){
    return std::string("Text");
}

bool Text::isClickable(){
    return false;
}
