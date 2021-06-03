#pragma once
#include<iostream>
#include "SDL2/SDL.h"


class Game{
    bool isGameRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Game();
    ~Game();

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool isRunning() const;
};