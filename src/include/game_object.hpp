#pragma once
#include<string>

class GameObject{
    int x;
    int y;

    int width;
    int height;

    std::string textureId;

public:
    GameObject(int x, int y, int width, int height,const std::string id);

    GameObject(const GameObject& other);
    GameObject& operator=(const GameObject& other);

    virtual ~GameObject();

    /**
     * Getters
     */
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureId() const;

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

};