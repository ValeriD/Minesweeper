#pragma once
#include "SDL2/SDL.h"
#include "game.hpp"
#include "position2d.hpp"


enum MouseButtons{
    LEFT = 0,
    RIGHT = 1
};
class InputHandler{

    bool states[2];
    InputHandler();
public:
    static InputHandler* getInstance();

    void update();

    bool getState(unsigned button);

    const Position2D getMousePosition()const;
};