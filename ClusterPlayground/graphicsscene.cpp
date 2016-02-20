#include "graphicsscene.h"
#include "distance.h"

#include <QGraphicsSceneMouseEvent>

GraphicsScene::GraphicsScene(int x0, int y0, int w, int h, QObject *parent) : QGraphicsScene(parent),centersIndex(),transform(1,0,0,0,1,0,0,0,1){
    dotRadius = 10;
    selectionActive = false;
    setSceneRect(x0,y0,w,h);
}

GraphicsScene::~GraphicsScene(){
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (itemAt(event->scenePos().x(),event->scenePos().y(),transform) == 0){
        if (event->button() == Qt::LeftButton){
            addItem(new Dot(event->scenePos(),dotRadius,Qt::white));

            if(!centersIndex.isEmpty()){
                //creates a new line between the new Dot and its nearest Center
            }
        }
        else{
            addItem(new Dot(event->scenePos(),dotRadius,Qt::red));
            ((Dot*)items().last())->makeCenter();
            centersIndex.append(items().size()-1);
        }
    }
    else{
        selectionActive = true;
        selectedDot = itemAt(event->scenePos().x(),event->scenePos().y(),transform);
    }
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event){
    removeItem(itemAt(event->scenePos().x(),event->scenePos().y(),transform));
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
    if (selectionActive){
        ((Dot*)selectedDot)->setPos(event->scenePos());
        update(this->sceneRect());
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
    selectionActive = false;
}

Dot* GraphicsScene::nearestCenter(Dot *dot){
    double nearestDistance = sceneRect().width();
    int nearestCenterIndex = 0;

    for(int i = 0; i < centersIndex.size(); i++){
        Dot *center = ((Dot*)items().at(centersIndex.at(i)));
        double newDistance = distance(dot->getPos(),center->getPos());

        if(newDistance < nearestDistance){
            nearestDistance = newDistance;
            nearestCenterIndex = centersIndex.at(i);
        }
    }

    return ((Dot*)items().at(nearestCenterIndex));
}

