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


    
    this->board = new Board(0,0,640,320, "cellImage", 10,20,50);
}
void Game::render(){
    SDL_RenderClear(renderer);
    this->board->draw();
    // Cell cell(0,0, 32,32,"cellImage",nullptr);
    // cell.draw();
    SDL_RenderPresent(renderer);
}
void Game::update(){
    board->update();
}
void Game::handleEvents(){
    InputHandler::getInstance()->update();
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

const SDL_Renderer* Game::getRenderer() const{
    return this->renderer;
}
SDL_Renderer* Game::getRenderer(){
    return this->renderer;
}
void Game::quit(){
    this->isGameRunning=false;
}