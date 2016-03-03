#include "graphicsscene.h"
#include "costscene.h"

#include <QApplication>
#include <QGraphicsView>
#include <sstream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicsScene scene(0,0,500,500);
    //---------------
    CostScene cost_scene(0,0,150,50);
    QGraphicsView cost_view;

    QObject::connect(&scene,SIGNAL(costChanged(double)),&cost_scene,SLOT(setCost(double)));

    cost_view.setScene(&cost_scene);
    cost_view.setFixedSize(155,55);

    cost_view.show();
    //-------------------
    QGraphicsView view;

    view.setScene(&scene);
    view.setFixedSize(510,510);

    QCoreApplication::setApplicationName("Cluster Playground");
    view.show();

    return a.exec();
}
