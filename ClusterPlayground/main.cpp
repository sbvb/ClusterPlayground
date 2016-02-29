#include "graphicsscene.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphicsScene scene;
    QGraphicsView view;

    view.setScene(&scene);
    view.setFixedSize(510,510);

    view.show();

    return a.exec();
}
