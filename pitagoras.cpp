#include "pitagoras.h"
#include <math.h>

double pitagoras(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
