#include "distance.h"
#include <math.h>

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double distance(QPointF dot1, QPointF dot2){
    return sqrt(pow(dot1.x() - dot2.x(), 2) + pow(dot1.y() - dot2.y(), 2));
}
