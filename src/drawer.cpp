#include "./include/drawer.hpp"

void Drawer::drawZero(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 0,0, position, width,height,Game::getInstance()->getRenderer());
}
void Drawer::drawOne(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 0,1, position,width,height,Game::getInstance()->getRenderer());
}
void Drawer::drawTwo(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 0,2, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawThree(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 0,3, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawFour(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 1,0, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawFive(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 1,1, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawSix(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 1,2, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawSeven(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 1,3, position,width,height,Game::getInstance()->getRenderer());

}
void Drawer::drawEight(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 2,0, position,width,height,Game::getInstance()->getRenderer());
}
void Drawer::drawClosed(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 2,1, position,width,height,Game::getInstance()->getRenderer());
}
void Drawer::drawClickedBomb(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 2,2, position,width,height,Game::getInstance()->getRenderer());
}
void Drawer::drawFlagged(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 2,3, position,width,height,Game::getInstance()->getRenderer());
}

void Drawer::drawOpenedBomb(const Position2D& position, int width, int height){
    TextureManager::getInstance()->draw("cellImage", 3,2, position,width,height,Game::getInstance()->getRenderer());

}