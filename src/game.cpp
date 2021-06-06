#include "./include/game.hpp"


Game::Game(){

}
Game::~Game(){
    this->clean();
}

Game* Game::getInstance(){
    static Game instance;
    return &instance;
}

void Game::init(const char* title, int xpos, int ypos, int width, int height){

    //Initialization of all SDL components - Video, Audio ...
    if(SDL_Init(SDL_INIT_EVERYTHING) ==0){
        std::cout<< "SDL initialized successfully"<< std::endl;
        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

        //Check if the window is successfully created
        if(this->window!=0){
            std::cout<< "Window created successfully"<< std::endl;
            this->renderer = SDL_CreateRenderer(this->window,-1,0); //Create renderer

            //Check if the renderer is successfully created
            if(this->renderer!=0){
                std::cout<< "Renderer created successfully!"<< std::endl;
                SDL_SetRenderDrawColor(this->renderer, 255,255,255,255); //Set the renderer color to be white
            }else{ //On renderer creation failure
                throw std::runtime_error(SDL_GetError());
            }
        }else{ //On window creation failure
            throw std::runtime_error(SDL_GetError());
        }
    }else{ // On initialization failure
        throw std::runtime_error(SDL_GetError());
    }

    std::cout<<"Initialization finished successfully!"<< std::endl;
    this->isGameRunning = true;

    TextureManager::getInstance()->load("./assets/cell.png","cellImage",this->renderer);

}
void Game::render(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
void Game::update(){


}
void Game::handleEvents(){

    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT: this->isGameRunning=false; break;

            default: break;
        }
    }
}
void Game::clean(){
    std::cout<<"Cleaning the game"<< std::endl;
    
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

bool Game::isRunning() const{
    return this->isGameRunning;
}