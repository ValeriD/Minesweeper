#pragma once
#include<string>
#include "texture_manager.hpp"
#include "game.hpp"

/**
 * Static Class that draws the game objects on the screen
 */
class Drawer{

    Drawer();
public:
    Drawer(const Drawer& other) = delete;
    Drawer& operator=(const Drawer& other) = delete;
    
    //TODO add width parameter because of the different levels
    /**
     * Method that draws the coresponding value/state of cell
     */
    static void drawZero(int x, int y);
    static void drawOne(int x, int y);
    static void drawTwo(int x, int y);
    static void drawThree(int x, int y);
    static void drawFour(int x, int y);
    static void drawFive(int x, int y);
    static void drawSix(int x, int y);
    static void drawSeven(int x, int y);
    static void drawEight(int x, int y);
    static void drawClosed(int x, int y);
    static void drawOpenedBomb(int x, int y);
    static void drawClickedBomb(int x, int y);
    static void drawFlagged(int x, int y);
};