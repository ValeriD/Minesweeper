#include<iostream>
#include<SDL2/SDL.h>
#include"include/game.hpp"

int main(){


    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Success"<<std::endl;
    }
    Game* game = new Game();

    if(!game->init("Minesweeper", 100,100, 640,480,0)){
        return -1;
    }

    while(game->isRunning()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    return 0;
}