#pragma once
#include "game_object.hpp"


class Board;

enum CellState{
    FLAGGED, OPENED, CLOSED
};

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

    /**
     * Setters
     */
    void setState(size_t flag);
    void setToBomb();

    /**
     * Method that calculates the number of surrounding bombs
     */
    void calculateNumSurroundingBombs(size_t row, size_t col);

    /**
     * Implementation of the GameObject virtual methods
     */
    void draw();
    void update();
    void clean();
};