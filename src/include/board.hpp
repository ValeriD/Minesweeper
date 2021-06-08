#pragma once
#include<vector>
#include<iostream>
#include "game_object.hpp"
#include "cell.hpp"



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

    //TODO
    void openCell(size_t row, size_t col);

    /**
     * Implementation of the GameObject virtual methods
     */
    void draw();
    void update();
    void clean();

};