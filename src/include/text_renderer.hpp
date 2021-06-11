#pragma once
#include<string>
#include<iostream>
#include "SDL2/SDL.h"
#include <SDL2/SDL_ttf.h>
#include "game.hpp"

/**
 * Static class that is rendering a text
 */
class TextRenderer{

    /**
     * Private default constructor
     */
    TextRenderer();

public:

    /**
     * Deleted copy constructor and assign operator
     */
    TextRenderer(const TextRenderer& other) = delete;
    TextRenderer& operator=(const TextRenderer& other) = delete;

    /**
     * Static method for rendering a text
     * @param text
     * @param color
     * @param x - position on the screen
     * @param y - position on the screen
     * @param width
     * @param height
     */
    static void renderText(const std::string& text, SDL_Color color, int x, int y, int width, int height);
};