#ifndef GRAPHICSSCENE
#define GRAPHICSSCENE

#include <vector>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QTransform>
#include <QPointF>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(int x0 = 0, int y0 = 0,
                  int w = 500, int h = 500,
                  QObject *parent = 0);
    ~GraphicsScene();
    int nearestRed(int whiteIndex);

protected:
    int DotRadius;
    std::vector<int> redDotsIndex;

    bool selectionActive;
    QGraphicsItem * selectedDot;
    QTransform transform;

    // overrides
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *);
};

#endif // GRAPHICSSCENE

