#pragma once
#include<string>
#include "texture_manager.hpp"
#include "game.hpp"
#include "position2d.hpp"

/**
 * Static Class that draws the game objects on the screen
 */
class Drawer{

    Drawer();
public:
    Drawer(const Drawer& other) = delete;
    Drawer& operator=(const Drawer& other) = delete;
    
    //TODO add width parameter because of the different levels and textureId as param too
    /**
     * Method that draws the coresponding value/state of cell
     */
    static void drawZero(const Position2D& position, int width, int height);
    static void drawOne(const Position2D& position, int width, int height);
    static void drawTwo(const Position2D& position, int width, int height);
    static void drawThree(const Position2D& position, int width, int height);
    static void drawFour(const Position2D& position, int width, int height);
    static void drawFive(const Position2D& position, int width, int height);
    static void drawSix(const Position2D& position, int width, int height);
    static void drawSeven(const Position2D& position, int width, int height);
    static void drawEight(const Position2D& position, int width, int height);
    static void drawClosed(const Position2D& position, int width, int height);
    static void drawOpenedBomb(const Position2D& position, int width, int height);
    static void drawClickedBomb(const Position2D& position, int width, int height);
    static void drawFlagged(const Position2D& position, int width, int height);
};