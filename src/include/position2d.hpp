#pragma once

class Position2D{
    int x;
    int y;
public:
    Position2D();

    Position2D(int x, int y);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);
};