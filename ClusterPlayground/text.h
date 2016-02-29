#ifndef TEXT_H
#define TEXT_H

#include "customitem.h"

#include <QGraphicsItem>
#include <QPointF>

#include <string>

class Text : public CustomItem
{
    QPointF m_position;
    double m_width;
    double m_heigth;
    const char* m_fixed_text;
    std::string m_text_complement;
public:
    Text(QPointF position, double width, double heigth, const char *fixed_text, QGraphicsItem *parent = 0);
    Text(double positionx, double positiony, double width, double heigth, const char *fixed_text, QGraphicsItem *parent = 0);

    void setTextComplement(std::string);

    std::string getName();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TEXT_H
