#include "text.h"

#include <sstream>

#include <QPainter>
#include <QString>

Text::Text(double positionx, double positiony, double width, double heigth, const char *fixed_text, QGraphicsItem *parent) : CustomItem(parent)
{
    m_position = QPointF(positionx,positiony);
    m_width = width;
    m_heigth = heigth;
    m_fixed_text = fixed_text;
}

Text::Text(QPointF position, double width, double heigth, const char *fixed_text, QGraphicsItem *parent) : CustomItem(parent)
{
    m_position = position;
    m_width = width;
    m_heigth = heigth;
    m_fixed_text = fixed_text;
}

void Text::setTextComplement(std::string text_complement){
    m_text_complement = text_complement;
}

QRectF Text::boundingRect() const
{
    return QRectF(m_position,m_position+QPointF(m_width,m_heigth));
}

void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    std::stringstream temp_str;
    temp_str << m_fixed_text << m_text_complement;
    std::string str = temp_str.str();
    painter->drawText(m_position,QString(str.c_str()));
}

std::string Text::getName(){
    return std::string("Text");
}
