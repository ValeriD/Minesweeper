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
    return this->cells[row*cols + col];
}

void Board::openCell(size_t row, size_t col){
    if(!(this->at(row, col)->isFlaged() || this->at(row, col)->isOpened())){
        this->at(row, col)->setState(3);
        if(this->at(row, col)->isBomb()){
        //End the game and open all bombs
        }else if(this->at(row, col)->getNumberOfSurroundingBombs() == 0){
            if(row > 0) openCell(row-1, col);
            if(row < rows -1) openCell(row+1, col);
            if(col > 0) openCell(row, col-1);
            if(col < cols-1) openCell(row, col+1);
        } 
    }

}


int Board::calculateRow(int cursorY)const{
    if(cursorY > this->getY()+this->getHeight() || cursorY < this->getY()){
        return -1;
    }
    return (cursorY - this->getY())/(this->getHeight()/rows);
}
int Board::calculateCol(int cursorX)const{
    if(cursorX > this->getX()+this->getWidth() || cursorX < this->getX()){
        return -1;
    }
    return (cursorX - this->getX())/(this->getWidth()/cols);
}
void Board::draw(){
    for(auto cell: this->cells){
        cell->draw();
    }
}
void Board::update(){
    //Check for win condition
    if(InputHandler::getInstance()->getState(0)){
        Position2D p = InputHandler::getInstance()->getMousePosition();
        int row = this->calculateRow(p.getY());
        int col = this->calculateCol(p.getX());

        if(row>=0 && col>=0){
            //check if is a bomb end the game
            openCell(row,col);
        }
    }
    if(InputHandler::getInstance()->getState(1)){
        Position2D p = InputHandler::getInstance()->getMousePosition();
        int row = this->calculateRow(p.getY());
        int col = this->calculateCol(p.getX());
        if(row>=0 && col>=0){
            if(this->at(row, col)->isFlaged()) this->at(row, col)->setState(2);
            else this->at(row,col)->setState(1);
        }
    }
}

void Board::genereateBombs(){
    size_t row, col;
    srand(time(NULL));
    for(size_t i = 0; i < this->numBombs; i++){
        do{
            row = rand() % this->rows;
            col = rand() % this->cols;
        }while(this->at(row, col)->isBomb());

        this->at(row, col)->setToBomb();
    }
}

Cell* Board::getCellByCursorPos(const Position2D& pos){
    if(pos.getX()> this->getX()+this->getWidth() || pos.getX() < this->getX() 
    || pos.getY() > this->getY()+this->getHeight() || pos.getY() < this->getY()){
        return nullptr;
    }

    int col = (pos.getX() - this->getX())/(this->getWidth()/cols);
    int row = (pos.getY() - this->getY())/(this->getHeight()/rows);

    return at(row, col);
}
