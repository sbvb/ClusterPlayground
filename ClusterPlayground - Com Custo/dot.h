#ifndef DOT_H
#define DOT_H

#include "customitem.h"
#include "connection.h"

#include <QPointF>
#include <QRectF>

#include <QPainter>
#include <QBrush>

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class Dot : public CustomItem
{
    QBrush m_brush;
    QPointF m_pos;
    Connection *m_connection;
    double m_radius;
    bool m_isCenter;
public:
    Dot(double x, double y, double dotRadius, Qt::GlobalColor, QGraphicsItem *parent = 0);
    Dot(QPointF pos, double dotRadius, Qt::GlobalColor, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setConnection(Connection *connection);
    void setPos(QPointF pos);
    void setPos(double x, double y);
    void makeCenter();

    std::string getName();
    QPointF getPos();
    QPointF *getPosPointer();
    Connection *getConnection();

    bool isClickable();
    bool isCenter();
};

#endif // DOT_H

