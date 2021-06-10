#include "./include/game_object.hpp"

GameObject::GameObject(int x, int y, int width, int height,const std::string id)
: position(Position2D(x,y)), width(width), height(height), textureId(id)
{
}

GameObject::~GameObject(){}

GameObject::GameObject(const GameObject& other)
:  GameObject(other.getX(), other.getY(), other.width, other.height, other.textureId)
{
}

GameObject& GameObject::operator=(const GameObject& other){
    if(this == &other){
        return *this;
    }
    this->position = other.position;
    this->width = other.width;
    this->height = other.height;
    this->textureId = other.textureId;

    return *this;
}

int GameObject::getX() const{
    return this->position.getX();
}
int GameObject::getY() const{
    return this->position.getY();
}
const Position2D& GameObject::getPosition() const{
    return this->position;
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