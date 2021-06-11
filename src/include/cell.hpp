#pragma once
#include "game_object.hpp"
#include "drawer.hpp"

class Board;


/**
 * Enum that represents the cell states
 */
enum CellState{
    FLAGGED, OPENED, CLOSED
};

/**
 * Cell class that represents single cell of the monefield
 * @param bomb - true if the cell is bomb
 * @param numSurroundingBombs 
 * @param state - the state of the cell
 * @param board - the parent
 */
class Cell: public GameObject{

    bool bomb;
    CellState state;
    size_t numSurroundingBombs;
    Board* board;

public:
    /**
     * Constructor of single Cell
     * @param x - position on the screen
     * @param y - position on the screen
     * @param width - width of the texture
     * @param height - height of the texture
     * @param id - the texture ID
     * @param board - pointer to the parent
     */
    Cell(int x, int y, int width, int height, std::string id, Board* board);

    /**
     * Destrucor
     */
    virtual ~Cell();
    /**
     * Copy constructor
     * @param other
     */
    Cell(const Cell& other);

    /**
     * Assign operator
     * @param other
     */
    Cell& operator=(const Cell& other);

    /**
     * State checkeres
     */
    bool isFlaged() const;
    bool isClosed() const;
    bool isOpened() const;
    bool isBomb() const;
    int getNumberOfSurroundingBombs() const;

    /**
     * Setters
     */
    void setState(size_t flag);
    void setToBomb();

    /**
     * Method that calculates the number of surrounding bombs
     * @param row - the row on which the cell is located
     * @param col- the column on which the cell is located
     */
    void calculateNumSurroundingBombs(size_t row, size_t col);

    /**
     * Method that draws copy of the cell on the renderer
     */
    void draw();
    void update();

    /**
     * Method that updates the state of the cell
     */
    void update(bool state);
};