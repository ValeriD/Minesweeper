#include "./include/drawer.hpp"

void Drawer::drawZero(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 0,0, x, y,32,32,Game::getInstance()->getRenderer());
}
void Drawer::drawOne(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 0,1, x, y,32,32,Game::getInstance()->getRenderer());
}
void Drawer::drawTwo(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 0,2, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawThree(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 0,3, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawFour(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 1,0, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawFive(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 1,1, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawSix(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 1,2, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawSeven(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 1,3, x, y,32,32,Game::getInstance()->getRenderer());

}
void Drawer::drawEight(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 2,0, x, y,32,32,Game::getInstance()->getRenderer());
}
void Drawer::drawClosed(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 2,1, x, y,32,32,Game::getInstance()->getRenderer());
}
void Drawer::drawClickedBomb(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 8,2, x, y,32,32,Game::getInstance()->getRenderer());
}
void Drawer::drawFlagged(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 8,3, x, y,32,32,Game::getInstance()->getRenderer());
}

void Drawer::drawOpenedBomb(int x, int y){
    TextureManager::getInstance()->draw("cellImage", 9,2, x, y,32,32,Game::getInstance()->getRenderer());

}