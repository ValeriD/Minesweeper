#include "./include/drawer.hpp"


void Drawer::drawZero(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 0,0, x, y,32,32,renderer);
}
void Drawer::drawOne(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 0,1, x, y,32,32,renderer);
}
void Drawer::drawTwo(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 0,2, x, y,32,32,renderer);

}
void Drawer::drawThree(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 0,3, x, y,32,32,renderer);

}
void Drawer::drawFour(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 1,0, x, y,32,32,renderer);

}
void Drawer::drawFive(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 1,1, x, y,32,32,renderer);

}
void Drawer::drawSix(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 1,2, x, y,32,32,renderer);

}
void Drawer::drawSeven(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 1,3, x, y,32,32,renderer);

}
void Drawer::drawEight(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 2,0, x, y,32,32,renderer);
}
void Drawer::drawClosed(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 2,1, x, y,32,32,renderer);
}
void Drawer::drawClickedBomb(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 8,2, x, y,32,32,renderer);
}
void Drawer::drawFlagged(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 8,3, x, y,32,32,renderer);
}

void Drawer::drawOpenedBomb(int x, int y,SDL_Renderer* renderer){
    TextureManager::getInstance()->draw("cellImage", 9,2, x, y,32,32,renderer);

}