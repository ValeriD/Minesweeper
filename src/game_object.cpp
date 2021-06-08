#include "./include/game_object.hpp"

GameObject::GameObject(int x, int y, int width, int height,const std::string id)
: x(x), y(y), width(width), height(height), textureId(id)
{
}

GameObject::~GameObject(){}

GameObject::GameObject(const GameObject& other)
:  GameObject(other.x, other.y, other.width, other.height, other.textureId)
{
}

GameObject& GameObject::operator=(const GameObject& other){
    if(this == &other){
        return *this;
    }
    this->x = other.x;
    this->y = other.y;
    this->width = other.width;
    this->height = other.height;
    this->textureId = other.textureId;

    return *this;
}

int GameObject::getX() const{
    return this->x;
}
int GameObject::getY() const{
    return this->y;
}
int GameObject::getWidth() const{
    return this->width;
}
int GameObject::getHeight() const{
    return this->height;
}
std::string GameObject::getTextureId() const{
    return this->textureId;
}