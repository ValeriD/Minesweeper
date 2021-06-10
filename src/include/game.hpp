#pragma once
#include<iostream>
#include "SDL2/SDL.h"
#include "texture_manager.hpp"
#include "input_handler.hpp"
#include "drawer.hpp"
#include "board.hpp"

class Board;
class InputHandler;
/**
 * Singleton class that represents the game
 * @param isGameRunning - variable that indicates if the game is still running
 * @param window - pointer to the SDL object that creates the graphic window
 * @param renderer - pointer to the SDL object that sets what to be displayed on the screen
 */
class Game{
    bool isGameRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    Board* board;
    /**
     * Private default constructor
     */
    Game();
public:
    /**
     * Destructor
     */
    ~Game();


    /**
     * Deleted assign operator and copy constructor
     */
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;

    /**
     *  Method that creates static instance of the class
     */
    static Game* getInstance();

    /**
     * Method that initialzie the game
     * @param title - the title of the window
     * @param xpos - x position of the screen on which the window to be displayed
     * @param ypos -  y position of the screen on which the window to be displayed
     * @param width - the width of the screeen
     * @param height - the height of the screen
     * 
     * @throw runtime_error when SDL fails
     */
    void init(const char* title, int xpos, int ypos, int width, int height);
    
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit();

    bool isRunning() const;

    const SDL_Renderer* getRenderer() const;

    SDL_Renderer* getRenderer();
};