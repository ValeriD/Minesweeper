#pragma once
#include<string>
#include<iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include "game.hpp"

class TextRenderer{


    TextRenderer();

public:
    static void renderText(const std::string& text, SDL_Color color, int x, int y, int width, int height);
};