#pragma once
#include<vector>
#include<iostream>
#include<time.h>
#include "game_object.hpp"
#include "cell.hpp"

class Cell;

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
     * @throw invalid_argument index out of range
     */
    const Cell* at(size_t row, size_t col) const;
    Cell* at(size_t row, size_t col);

    void openCell(size_t row, size_t col);

    int calculateRow(int cursorY)const;
    int calculateCol(int cursorX)const;

    /**
     * Implementation of the GameObject virtual methods
     */
    void draw();
    void update();

    void openAllBombs();
    Cell* getCellByCursorPos(const Position2D& pos);
};