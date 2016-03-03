#include "costscene.h"
#include "text.h"

CostScene::CostScene(int x0, int y0, int w, int h, QObject *parent):QGraphicsScene(parent){
    setSceneRect(x0,y0,w,h);
    addItem(new Text(x0+w/10,y0+h/5,w,h,"Total Cost: "));
}

CostScene::~CostScene(){
    delete items().last();
}

void CostScene::setCost(double cost){
    ((Text*)items().last())->setTotalCost(cost);
    update(sceneRect());
}
