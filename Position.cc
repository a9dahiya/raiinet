#include "Position.h"
#include <string>
using namespace std;



Position::Position(int row, int col) : row{row}, col{col}{}

int Position::getRow() const {
    return row;
}

int Position::getCol() const {
    return col;
}

bool Position::operator==(const Position& other) const{
    return (row == other.getRow() && col == other.getCol());
}

Position Position::operator+(const string& dir){
    if (dir == "up"){
        row--;
    }
    if (dir == "down"){
        row++;
    }
    if(dir == "left"){
        col--;
    }
    if(dir == "right"){
        col++;
    }

    return Position{};
}