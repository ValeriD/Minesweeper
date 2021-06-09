#include "./include/cell.hpp"
#include "./include/board.hpp"


Cell::Cell(int x, int y, int width, int height, std::string id, Board* board)
    : GameObject(x, y, width, height, id),
      bomb(false),
      state(CLOSED),
      numSurroundingBombs(-1),
      board(board)
{}

Cell::~Cell(){
}

Cell::Cell(const Cell& other)
    :  GameObject(other),
        bomb(other.bomb),
        state(other.state),
        numSurroundingBombs(other.numSurroundingBombs),
        board(other.board)
{}

Cell& Cell::operator=(const Cell& other){
    if(this == &other) return *this;

    GameObject::operator=(other);
    this->state = other.state;
    this->numSurroundingBombs = other.numSurroundingBombs;
    this->bomb = other.bomb;
    this->board = other.board;

    return *this;
}

bool Cell::isFlaged() const{
    return this->state == FLAGGED;
}
bool Cell::isClosed() const{
    return this->state == CLOSED;
}
bool Cell::isOpened() const{
    return this->state == OPENED;
}
bool Cell::isBomb() const{
    return this->bomb;
}
void Cell::setState(size_t flag){
    switch(flag){
        case 1: this->state = FLAGGED; break;
        case 2: this->state = CLOSED; break;
        case 3: this->state = OPENED; break;
        default: this->state = CLOSED; break;
    }
}

void Cell::setToBomb(){
    this->bomb = true;
}

void Cell::calculateNumSurroundingBombs(size_t row, size_t col){
    if(row > 0  && this->board->at(row-1, col)->isBomb())numSurroundingBombs++;
    if(row < this->board->getRowsCount() && this->board->at(row+1, col)->isBomb())numSurroundingBombs++;

    if(col > 0 && this->board->at(row, col-1)->isBomb()) numSurroundingBombs++;
    if(col < this->board->getColsCount()-1 && this->board->at(row, col+1)->isBomb()) numSurroundingBombs++;

    if(row > 0){
        if(col > 0 && this->board->at(row-1,col-1)->isBomb()) numSurroundingBombs++;
        if(col < this->board->getColsCount()-1 && this->board->at(row-1, col+1)->isBomb()) numSurroundingBombs++;
    }else if(row < this->board->getRowsCount()-1){
        if(col > 0 && this->board->at(row+1,col-1)->isBomb()) numSurroundingBombs++;
        if(col < this->board->getColsCount()-1 && this->board->at(row+1, col+1)->isBomb()) numSurroundingBombs++;
    }
}
void Cell::draw(){
    // switch(this->state){
    //     case FLAGGED: Drawer::drawFlagged(this->getX(), this->getY());break;
    //     case CLOSED: Drawer::drawClosed(this->getX(), this->getY());break;
    //     case OPENED: {
    //         if(this->isBomb()){
    //             //Drawer::draw
    //         }
    //     }
    // }
}
void Cell::update(){

}