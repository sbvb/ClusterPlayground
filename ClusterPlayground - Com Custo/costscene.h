#ifndef COSTSCENE
#define COSTSCENE

#include <QGraphicsScene>

class CostScene : public QGraphicsScene
{
    Q_OBJECT

public:
    CostScene(int x0 = 0, int y0 = 0,
                  int w = 500, int h = 500,
                  QObject *parent = 0);
    ~CostScene();

public slots:
    void setCost(double cost);

};
#endif // COSTSCENE

