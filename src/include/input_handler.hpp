#pragma once
#include "SDL2/SDL.h"
#include "game.hpp"
#include "position2d.hpp"

/**
 * Enum that represents the mouse buttons
 */
enum MouseButtons{
    LEFT = 0,
    RIGHT = 1
};

/**
 * Class that handles the user's input
 */
class InputHandler{

    bool states[2];
    InputHandler();
public:
    /**
     * Static method for instantiating the handler
     */
    static InputHandler* getInstance();

    /**
     * Deleted copy constructor and assign operator
     */
    InputHandler(const InputHandler& other) = delete;
    InputHandler& operator=(const InputHandler& other) = delete;

    /**
     * Method that is reading all the inputs
     */
    void update();

    /**
     * Method that checks the button state
     * @param button
     */
    bool getState(unsigned button);

    /**
     * Method that retreves the posiotition of the cursor on the screen
     */
    const Position2D getMousePosition()const;
};