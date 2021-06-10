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

    const int fps = 60;
    const int frameDelay = 1000/fps;

    Uint32 frameStart;
    int frameTime;


    while(game->isRunning()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
    
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay>frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        
    }

    return 0;
}