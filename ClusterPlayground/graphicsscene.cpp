#include "graphicsscene.h"
#include "distance.h"
#include "connection.h"
#include "text.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include <string>

GraphicsScene::GraphicsScene(int x0, int y0, int w, int h, QObject *parent) : QGraphicsScene(parent),centersPointers(),transform(1,0,0,0,1,0,0,0,1){
    dotRadius = 10;
    selectionActive = false;
    setSceneRect(x0,y0,w,h);
//    addItem(new Text(10,10,100,20,"Total Cost: "));
}

GraphicsScene::~GraphicsScene(){
    for(int i = 0;i < items().size();i++){
        delete items().at(i);
    }
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem *activeItem = itemAt(event->scenePos().x(),event->scenePos().y(),transform);

    if (activeItem != 0 and ((CustomItem*)activeItem)->isClickeable()){

        if(((CustomItem*)activeItem)->getName() == std::string("Dot")){
            selectionActive = true;
            selectedDot = ((Dot*)activeItem);
        }
    }
    else{
        if (event->button() == Qt::LeftButton){
            QGraphicsItem *newDot = new Dot(event->scenePos(),dotRadius,Qt::white);
            addItem(newDot);
            connectToNearest(((Dot*)newDot));
        }
        else{
            QGraphicsItem *newDot = new Dot(event->scenePos(),dotRadius,Qt::red);
            addItem(newDot);
            ((Dot*)newDot)->makeCenter();
            centersPointers.append(((Dot*)newDot));
            updateConnections();
        }

    }
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem *activeItem = itemAt(event->scenePos().x(),event->scenePos().y(),transform);

    if(((CustomItem*)activeItem)->isClickeable()){
        if(((Dot*)activeItem)->isCenter()){
            removeCenter(((Dot*)activeItem));
            updateConnections();
        }
        else{
            if(!centersPointers.isEmpty()){
                removeItem((QGraphicsItem*)((Dot*)activeItem)->getConnection());
            }
            removeItem(activeItem);
            update(sceneRect());
        }
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
    if (selectionActive){
        selectedDot->setPos(event->scenePos());
        if (selectedDot->isCenter()){
            updateConnections();
        }
        else{
            if(!centersPointers.isEmpty()){
                removeItem(((QGraphicsItem*)selectedDot->getConnection()));
            }
            connectToNearest(selectedDot);
        }
        update(sceneRect());
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
    selectionActive = false;
}

void GraphicsScene::updateConnections(){
    int i = 0;
    while(i<items().size()){
        QGraphicsItem *activeItem = items().at(i);
        if(((CustomItem*)activeItem)->getName() == std::string("Connection")){
            removeItem(activeItem);
        }
        else{
            i++;
        }
    }
    i = 0;
    while(i<items().size()){
        QGraphicsItem *activeItem = items().at(i);
        if(((CustomItem*)activeItem)->getName() == std::string("Dot")){
            Dot *dot = ((Dot*)activeItem);
            if(!dot->isCenter()){
                connectToNearest(dot);
            }
            else{
            }
        }
        i++;
    }
    update(sceneRect());
}

Dot* GraphicsScene::nearestCenter(Dot *dot){
    double nearestDistance = sceneRect().width();
    Dot *nearestCenterPointer;
    for(int i = 0; i < centersPointers.size(); i++){
        Dot *center = centersPointers.at(i);
        double newDistance = distance(dot->getPos(),center->getPos());

        if(newDistance < nearestDistance){
            nearestDistance = newDistance;
            nearestCenterPointer = centersPointers.at(i);
        }
    }

    return nearestCenterPointer;
}

void GraphicsScene::connectToNearest(Dot *start){
    if(!centersPointers.isEmpty()){
        Dot *end = nearestCenter(start);

        QGraphicsItem *newConnection = new Connection(start->getPosPointer(),end->getPosPointer());

        addItem(newConnection);
        start->setConnection(((Connection*)newConnection));
        update(sceneRect());
    }
}

void GraphicsScene::removeCenter(Dot *center){
    removeItem(((QGraphicsItem*)center));
    centersPointers.removeOne(center);

}
