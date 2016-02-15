#include "ball.h"

Ball::Ball(int x, int y):m_x(x),m_y(y){}

void Ball::setPos(int x, int y){
    m_x = x;
    m_y = y;
}

int Ball::getX(){
    return m_x;
}

int Ball::getY(){
    return m_y;
}
