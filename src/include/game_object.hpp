#pragma once
#include<string>
#include"position2d.hpp"

/**
 * Class representing an object in the game
 * @param position on the screen
 * @param width of the object
 * @param height of the object
 * @param textureId - the ID of the texture it is using
 */
class GameObject{
    Position2D position;

    int width;
    int height;

    std::string textureId;

public:
    /**
     * Constructor
     * @param x
     * @param y
     * @param width
     * @param height
     * @param id
     */
    GameObject(int x, int y, int width, int height,const std::string id);

    /**
     * Copy constructor
     * @param other
     */
    GameObject(const GameObject& other);

    /**
     * Assign operator
     * @param other
     */
    GameObject& operator=(const GameObject& other);

    /**
     * Virtual destructor
     */
    virtual ~GameObject();

    /**
     * Getters
     */
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureId() const;

    /**
     * Virtual method for drawing the object on the screen
     */
    virtual void draw() = 0;
    /**
     * Virtual function for updating the state of the object
     */
    virtual void update() = 0;
};