#include "./include/game.hpp"


Game::Game(){

}
Game::~Game(){

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags){
    if(SDL_Init(SDL_INIT_EVERYTHING) ==0){
        std::cout<< "SDL initialized successfully"<< std::endl;
        this->window.createWindow(title, xpos, ypos, width, height,flags);

        if(this->window!=0){
            std::cout<< "Window created successfully"<< std::endl;
            this->renderer = SDL_CREATE_RENDERER(this->window,-1,0);

            if(this->renderer!=0){
                std::cout<< "Renderer created successfully!"<< std::endl;
                SDL_SetRenderDrawColor(this->renderer, 255,255,255,255); //
            }else{
                std::cout<< "Renderer creation failed!"<< std::endl;
                return false;
            }
        }else{
            std::cout<< "Window creation failed!"<< std::endl;
            return false;
        }
    }else{
        std::cout<< "SDL initialization failed"<< std::endl;
        return false;
    }

    std::cout<<"Initialization finished successfully!"<< std::endl;
    this->isRunning = true;
    return true;

}
Game::render(){
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
Game::update(){


}
Game::handleEvents(){

    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: isRunning=false; break;

            default: break;
        }
    }
}
Game::clean(){
    std::cout<<"Cleaning the game"<< std::endl;
    
    SDL_windowDestroy(this->window);
    SDL_rendererDestroy(this->renderer);
    SDL_Quit();
}

bool Game::isRunning() const{
    return this->isRunning;
}