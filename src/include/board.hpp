#pragma once
#include<vector>
#include<iostream>
#include<time.h>
#include "game_object.hpp"
#include "cell.hpp"

class Cell;


/**
 * Class that represents the minefield
 * @param rows - the number of rows of the field
 * @param cols - the number of columns of the field
 * @param numBombs - the number of the bombs in the field
 * @param openedCells - the number of the opened cells 
 * @param cells - vector of the cells in the field
 * 
 */
class Board: public GameObject{

    size_t rows;
    size_t cols;
    size_t numBombs;    
    size_t openedCells;
    std::vector<Cell*> cells;

    /**
     * Method that generates the bombs on the board
     */
    void genereateBombs();

public:
    /**
     * Board constructor
     * @param x - x position on the screen
     * @param y - y position on the screen
     * @param width - width of the board
     * @param height - height of the board
     * @param id - the id of the texture for the cells
     * @param rows - the number of rows
     * @param cols - the number of columns
     * @param numBombs - the number of bombs on the board
     */
    Board(int x, int y, int width, int height, std::string id, size_t rows, size_t cols, size_t numBombs);

    /**
     * Destructor
     */
    virtual ~Board();
    /**
     * Copy constructor
     * @param other
     */
    Board(const Board& other);

    /**
     * Assign operator
     * @param other
     */
    Board& operator=(const Board& other);


    /**
     * Getters
     */
    size_t getRowsCount()const;
    size_t getColsCount()const;

    /**
     * Method that returns the cell at given postion
     * @param row
     * @param col
     * 
     * @return cell at the given position
     * @throw invalid_argument index out of range
     */
    const Cell* at(size_t row, size_t col) const;
    Cell* at(size_t row, size_t col);

    /**
     * Method that opens a cell, an recursively opens all zero cells
     * @param row
     * @param col
     */
    void openCell(size_t row, size_t col);

    /**
     * Method that calculates the  row based on the mouse cursor position
     * @param cursorY
     */
    int calculateRow(int cursorY)const;
    
    /**
     * Method that calculates the col based on the moise cursor position
     * @param cursorX
     */
    int calculateCol(int cursorX)const;

    /**
     * Method that draws the field
     */
    void draw();
    /**
     * Method that waits for mouse click and the perform the opening or the flagging of a cell
     * It is llistening for mouse event onlu if the current game is running
     */
    void update();

    /**
     * Method that sets the state of all bomb cells to opened
     * This method is called when bomb is clicked
     */
    void openAllBombs();
};