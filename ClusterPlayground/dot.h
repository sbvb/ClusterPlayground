#ifndef DOT_H
#define DOT_H

#include <QPointF>
#include <QRectF>

#include <QPainter>
#include <QBrush>

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Dot : public QGraphicsItem
{
    QBrush m_brush;
    QPointF m_pos;
    double m_radius;
    bool m_isCenter;
public:
    Dot(double x, double y, double dotRadius, Qt::GlobalColor, QGraphicsItem *parent = 0);
    Dot(QPointF pos, double dotRadius, Qt::GlobalColor, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void makeCenter();
    void setPos(QPointF pos);
    void setPos(double x, double y);

    QPointF getPos();
    bool isCenter();
};

#endif // DOT_H

