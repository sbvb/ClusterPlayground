#include "distance.h"
#include <math.h>

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) +
                (y1-y2)*(y1-y2));
}

double distance(QPointF dot1, QPointF dot2){
    return sqrt((dot1.x()-dot2.x())*(dot1.x()-dot2.x()) +
                (dot1.y()-dot2.y())*(dot1.y()-dot2.y()));
}
