#pragma once
#include<iostream>


/**
 * Class that represents the position in the 2D space
 */
class Position2D{
    int x;
    int y;
public:
    /**
     * Default constructor
     */
    Position2D();

    /**
     * Constrictor with params
     * @param x position
     * @param y position
     */
    Position2D(int x, int y);

    /**
     * Getters
     */
    int getX() const;
    int getY() const;

    /**
     * Setters
     */
    void setX(int x);
    void setY(int y);

    /**
     * Overriden operator for printing the postion
     */
    friend std::ostream& operator<<(std::ostream& os, const Position2D& pos);
};