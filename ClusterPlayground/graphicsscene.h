#ifndef GRAPHICSSCENE
#define GRAPHICSSCENE

#include "dot.h"

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTransform>
#include <QPointF>
#include <QList>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(int x0 = 0, int y0 = 0,
                  int w = 500, int h = 500,
                  QObject *parent = 0);
    ~GraphicsScene();
    Dot *nearestCenter(Dot *);

protected:

    QList<int> centersIndex;
    int dotRadius;

    QTransform transform;
    QGraphicsItem * selectedDot;
    bool selectionActive;

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
};

#endif // GRAPHICSSCENE

