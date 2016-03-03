#ifndef TEXT
#define TEXT

#include <QGraphicsItem>

#include <QRectF>
#include <QPainter>

#include "customitem.h"

class Text : public CustomItem
{
    QPointF m_position;
    double m_width;
    double m_heigth;
    double m_total_cost;
    const char *m_fixed_text;

public:
    Text(QPointF position,double width, double heigth, const char *fixed_text, QGraphicsItem *parent = 0);
    Text(double x, double y,double width, double heigth, const char *fixed_text, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setTotalCost(double total_cost);

    bool isClickable();
    std::string getName();
};

#endif // TEXT

