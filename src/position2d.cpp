#include "./include/position2d.hpp"


Position2D::Position2D()
: x(0),y(0)
{}

Position2D::Position2D(int x,int y)
: x(x),y(y)
{}

int Position2D::getX() const{
    return this->x;
}
int Position2D::getY() const{
    return this->y;
}

void Position2D::setX(int x){
    this->x = x;
}
void Position2D::setY(int y){
    this->y = y;
}

