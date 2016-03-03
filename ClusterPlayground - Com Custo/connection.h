#ifndef CONNECTION
#define CONNECTION

#include <QGraphicsItem>

#include "customitem.h"

class Connection : public CustomItem
{
    QPointF *m_start;
    QPointF *m_end;
public:
    Connection(QPointF *start, QPointF *end, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isClickable();
    std::string getName();
    double getLength();
};

#endif // CONNECTION

