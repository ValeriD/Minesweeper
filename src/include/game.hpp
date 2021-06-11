#pragma once
#include<iostream>
#include "SDL2/SDL.h"
#include "texture_manager.hpp"
#include "input_handler.hpp"
#include "drawer.hpp"
#include "board.hpp"
#include "text_renderer.hpp"

class Board;
class InputHandler;
class TextRenderer;

/**
 * Enum that represents the current game state
 */
enum CurrentGameState{
    WIN = 1,
    LOSE = 2,
    RUNNING = 3
};

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

    int currentGameState;
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
    
    /**
     * Method that is responsibel for what is rendered on the user's screen
     */
    void render();
    /**
     * Method that is responsible for updating the game state
     */
    void update();
    /**
     * Method that is responisible for catching the needed events
     */
    void handleEvents();
    /**
     * Method for cleaning the game
     */
    void clean();
    /**
     * Method that is creating a new game - deletes the old board, if any, and generates a new one
     */
    void restart();

    /**
     * This method is used to stop the game loop
     */
    void quit();

    /**
     * Method that returns the global game state
     */
    bool isRunning() const;
    /**
     * Returns the status of the current game
     */
    int getCurrentGameState() const;

    /**
     * Setter for the current game
     */
    void setCurrentGameState(int flag);

    
    /**
     * Methods that returns the game renderer
     */
    const SDL_Renderer* getRenderer() const;
    SDL_Renderer* getRenderer();

    /**
     * Method that returns the game window
     */
    SDL_Window* getWindow();
};