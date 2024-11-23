#ifndef POSITION_H
#define POSITION_H

class Direction;

class Position {
public:
    int getRow();
    int getCol();
    bool operator==(const Position& other);
    Position operator+(const Direction& dir);

private:
    int row;
    int col;
};

#endif 
