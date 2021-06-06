#include "texture_manager.hpp"
#include<string>

/**
 * Static Class that draws the game objects on the screen
 */
class Drawer{

    Drawer();
public:
    Drawer(const Drawer& other) = delete;
    Drawer& operator=(const Drawer& other) = delete;
    

    /**
     * Method that draws the coresponding value/state of cell
     */
    static void drawZero(int x, int y, SDL_Renderer* renderer);
    static void drawOne(int x, int y,SDL_Renderer* renderer);
    static void drawTwo(int x, int y,SDL_Renderer* renderer);
    static void drawThree(int x, int y,SDL_Renderer* renderer);
    static void drawFour(int x, int y,SDL_Renderer* renderer);
    static void drawFive(int x, int y,SDL_Renderer* renderer );
    static void drawSix(int x, int y,SDL_Renderer* renderer);
    static void drawSeven(int x, int y,SDL_Renderer* renderer);
    static void drawEight(int x, int y,SDL_Renderer* renderer);
    static void drawClosed(int x, int y,SDL_Renderer* renderer);
    static void drawOpenedBomb(int x, int y,SDL_Renderer* renderer);
    static void drawClickedBomb(int x, int y,SDL_Renderer* renderer);
    static void drawFlagged(int x, int y,SDL_Renderer* renderer);
};