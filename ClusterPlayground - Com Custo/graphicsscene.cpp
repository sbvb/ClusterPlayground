#include "graphicsscene.h"
#include "distance.h"
#include "connection.h"

#include <QDebug>
#include <QGraphicsSceneMouseEvent>

#include <string>

GraphicsScene::GraphicsScene(int x0, int y0, int w, int h, QObject *parent) : QGraphicsScene(parent),centersPointers(),
                                                                              transform(1,0,0,0,1,0,0,0,1){
    dotRadius = 10;
    selectionActive = false;
    setSceneRect(x0,y0,w,h);
    totalCost = 0;
}

GraphicsScene::~GraphicsScene(){
    for(int i = 0;i < items().size();i++){
        delete items().at(i);
    }
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem *activeItem = itemAt(event->scenePos().x(),event->scenePos().y(),transform);

    if (activeItem != 0 and ((CustomItem*)activeItem)->isClickable()){
        QGraphicsItem *selection = itemAt(event->scenePos().x(),event->scenePos().y(),transform);

        if(((CustomItem*)selection)->getName() == std::string("Dot")){
            selectionActive = true;
            selectedDot = ((Dot*)selection);
        }
    }
    else{
        if (event->button() == Qt::LeftButton){
            QGraphicsItem *newDot = new Dot(event->scenePos(),dotRadius,Qt::white);
            addItem(newDot);
            connectToNearest(((Dot*)newDot));
            totalCost = calculateCost();
            emit costChanged(totalCost);
        }
        else{
            QGraphicsItem *newDot = new Dot(event->scenePos(),dotRadius,Qt::red);
            addItem(newDot);
            ((Dot*)newDot)->makeCenter();
            centersPointers.append(((Dot*)newDot));
            updateConnections();
            totalCost = calculateCost();
            emit costChanged(totalCost);
        }
    }
    update(QRectF(-50,-50,1000,1000));
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem *selection = itemAt(event->scenePos().x(),event->scenePos().y(),transform);

    if(((CustomItem*)selection)->getName() == std::string("Dot")){
        if(((Dot*)selection)->isCenter()){
            removeCenter(((Dot*)selection));
            updateConnections();
        }
        else{
            removeItem((QGraphicsItem*)((Dot*)selection)->getConnection());
            removeItem(selection);
        }
        totalCost = calculateCost();
        emit costChanged(totalCost);
        update(QRectF(-50,-50,1000,1000));
    }
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
    if (selectionActive){
        selectedDot->setPos(event->scenePos());
        if (selectedDot->isCenter()){
            updateConnections();
        }
        else{
            removeItem(((QGraphicsItem*)selectedDot->getConnection()));
            connectToNearest(selectedDot);
        }        
        totalCost = calculateCost();
        emit costChanged(totalCost);
        update(QRectF(-50,-50,1000,1000));
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
        }
        i++;
    }
    update(QRectF(-50,-50,1000,1000));
}

Dot* GraphicsScene::nearestCenter(Dot *dot){
    double nearestDistance = QRectF(-50,-50,1000,1000).width();
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
        update(QRectF(-50,-50,1000,1000));
    }
}

void GraphicsScene::removeCenter(Dot *center){
    removeItem(((QGraphicsItem*)center));
    centersPointers.removeOne(center);
}

double GraphicsScene::calculateCost(){
    double cost = 0;
    for(int i = 0; i < items().size(); i++){
        QGraphicsItem *activeItem = items().at(i);
        if(((CustomItem*)activeItem)->getName() == std::string("Connection")){
            cost += ((Connection*)activeItem)->getLength();
        }
    }
    return cost;
}

double *GraphicsScene::getCostPointer(){
    return &totalCost;
}
