#include<iostream>
#include<SDL2/SDL.h>
#include"include/game.hpp"

int main(){

    Game* game = Game::getInstance();

    try{
        game->init("Minesweeper", 100,100, 640,480);
    }catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
        return -1;
    }

    while(game->isRunning()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    return 0;
}