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
        if(TTF_Init()!=0){
            throw std::runtime_error("TTF not initialized");
        }
        std::cout<< "SDL initialized successfully"<< std::endl;
        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);

        //Check if the window is successfully created
        if(this->window!=0){
            std::cout<< "Window created successfully"<< std::endl;
            this->renderer = SDL_CreateRenderer(this->window,-1,0); //Create renderer

            //Check if the renderer is successfully created
            if(this->renderer!=0){
                std::cout<< "Renderer created successfully!"<< std::endl;
                SDL_SetRenderDrawColor(this->renderer, 0,0,0,0); //Set the renderer color to be white
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

    restart();

    
}
void Game::render(){
    SDL_RenderClear(renderer);

    this->board->draw();
    
    TextRenderer::renderText("Press R to restart the game", {255,255,255}, 0,330,320,50);
    switch(this->currentGameState){
        case WIN: TextRenderer::renderText("YOU WON", {255,255,255}, 0,390,320,50);break;
        case LOSE: TextRenderer::renderText("YOU LOST", {255,255,255}, 0,390,320,50);break; 
    }

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
    delete this->board;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    TTF_Quit();
    SDL_Quit();
}

void Game::restart(){
    if(this->board){
        delete this->board;
    }
    
    this->board = new Board(0,0,640,320, "cellImage", 10,20,10);
    this->currentGameState = RUNNING;

}

bool Game::isRunning() const{
    return this->isGameRunning;
}

int Game::getCurrentGameState()const{
    return this->currentGameState;
}

void Game::setCurrentGameState(int flag){
    this->currentGameState = flag;
}

const SDL_Renderer* Game::getRenderer() const{
    return this->renderer;
}
SDL_Renderer* Game::getRenderer(){
    return this->renderer;
}
SDL_Window* Game::getWindow(){
    return this->window;
}
void Game::quit(){
    this->isGameRunning=false;
}