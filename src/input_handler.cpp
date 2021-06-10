#include "./include/input_handler.hpp"


InputHandler::InputHandler(){
    for(unsigned i = 0; i < 2; i++){
        states[i]=false;
    }
}

InputHandler* InputHandler::getInstance(){
    static InputHandler instance;
    return& instance;
}

void InputHandler::update(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            Game::getInstance()->quit();
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT){
                this->states[LEFT] = true;
            }else if(event.button.button == SDL_BUTTON_RIGHT){
                this->states[RIGHT] = true;
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                this->states[LEFT] = false;
            }else if(event.button.button == SDL_BUTTON_RIGHT){
                this->states[RIGHT] = false;
            }
        }
    }
    
}

bool InputHandler::getState(unsigned button){
    return states[button];
}

const Position2D InputHandler::getMousePosition()const{
    
    int x, y;
    SDL_GetGlobalMouseState(&x, &y);
    
    int windowX, windowY;
    SDL_GetWindowPosition(Game::getInstance()->getWindow(),&windowX, &windowY);
    
    Position2D pos;
    pos.setX(x - windowX);
    pos.setY(y - windowY);

    return pos;
}