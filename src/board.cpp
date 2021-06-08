#include "./include/board.hpp"


Board::Board(int x, int y, int width, int height, std::string id, size_t rows, size_t cols, size_t numBombs)
: GameObject(x, y, width, height, id),
    rows(rows), 
    cols(cols), 
    numBombs(numBombs),
    openedCells(0)
{
    size_t cellWidth = width / cols;
    size_t cellHeight = height / rows;
    for(size_t i = 0; i < rows; i++){
        for(size_t j=0; j< cols; j++){
            cells.push_back(new Cell(x+j*cellWidth,y+i*cellHeight, cellWidth,cellHeight, id, this));
        }
    }

    this->genereateBombs();

    for(size_t i = 0; i < rows; i++){
        for(size_t j=0; j< cols; j++){
            if(!this->at(i,j)->isBomb()){
                this->at(i,j)->calculateNumSurroundingBombs(i,j);
            }
        }
    }
}

Board::~Board(){
    for(size_t i = 0; i < rows*cols; i++){
        delete this->cells[i];
    }
    this->cells.clear();
}

Board::Board(const Board& other)
    :  GameObject(other),
    rows(other.rows), 
    cols(other.cols),
    numBombs(other.numBombs),
    openedCells(other.openedCells)
{
    this->cells = other.cells;
}

Board& Board::operator=(const Board& other){
    if(this == &other) return *this;

    GameObject::operator=(other);
    this->rows = other.rows;
    this->cols = other.cols;
    this->numBombs = other.numBombs;
    this->openedCells = other.openedCells;
    this->cells = other.cells;

    return *this;
}


size_t Board::getRowsCount()const{
    return this->rows;
}

size_t Board::getColsCount()const{
    return this->cols;
}


const Cell* Board::at(size_t row, size_t col) const{
    if(row < 0 || row >= this->rows || col < 0 || col >= this->cols) throw std::invalid_argument("Index out of bounds");
    return this->cells[row*col];
}
Cell* Board::at(size_t row, size_t col){
    return this->cells[row*col];
}

void Board::openCell(size_t row, size_t col){
}
void Board::draw(){
    //Draw every cell
}
void Board::update(){
    //Checks for input /Input handler
    //If found does the flag, or opens the cell
}
void Board::clean(){

}

void Board::genereateBombs(){
    size_t row, col;
    for(size_t i = 0; i < this->numBombs; i++){
        do{
            row = rand() % this->rows;
            col = rand() % this->cols;
        }while(this->at(row, col)->isBomb());

        this->at(row, col)->setToBomb();
    }
}
