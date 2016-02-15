#include "graphicsscene.h"
#include "pitagoras.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>

GraphicsScene::GraphicsScene(int x0, int y0, int w, int h, QObject *parent) : QGraphicsScene(parent),DotRadius(10),transform(1,0,0,0,1,0,0,0,1),selectionActive(false){
    redDotsIndex.resize(0);
    setSceneRect(x0,y0,w,h);
}

GraphicsScene::~GraphicsScene(){
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (itemAt(event->scenePos().x(),event->scenePos().y(),transform) == 0){
        if (event->button() == Qt::LeftButton){
            addEllipse(event->scenePos().x()-DotRadius,event->scenePos().y()-DotRadius,2*DotRadius,2*DotRadius,QPen(Qt::black),QBrush(Qt::white));
//            int a = nearestRed(items().size() - 1);
//            int b = 0;
//            bobeira qualquer pra testar 'nearestRed()'
        }
        else{
            redDotsIndex.resize(redDotsIndex.size()+1);
            redDotsIndex[redDotsIndex.size()-1] = items().size();
            addEllipse(event->scenePos().x()-DotRadius,event->scenePos().y()-DotRadius,2*DotRadius,2*DotRadius,QPen(Qt::black),QBrush(Qt::red));
        }
    }
    else{        
        selectionActive = true;
        selectedDot = itemAt(event->scenePos().x(),event->scenePos().y(),
                             QTransform(1,0,0,0,1,0,0,0,1));
    }
}

void GraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event){

}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
    if(selectionActive){
        selectedDot->setPos(event->scenePos());
    }
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
    selectionActive = false;
}

int GraphicsScene::nearestRed(int whiteIndex){
    //não funciona ainda
    qreal whiteX = items().at(whiteIndex)->x();
    qreal whiteY = items().at(whiteIndex)->y();

    int nearestIndex = 0;
    double nearestDistance = 0;

    for(unsigned int redIndex = 0;redIndex < redDotsIndex.size();redIndex++){

        double newDistance = pitagoras(whiteX,items().at(redDotsIndex[redIndex])->x(),
                                       whiteY,items().at(redDotsIndex[redIndex])->y());

        if(newDistance < nearestDistance){
            nearestIndex = redIndex;
            nearestDistance = newDistance;
        }
    }
    return nearestIndex;
}

