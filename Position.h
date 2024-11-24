#ifndef POSITION_H
#define POSITION_H

class Direction;

class Position {
public:
    Position(int row , int col);
    int getRow();
    int getCol();
    bool operator==(const Position& other) const;
    Position operator+(const Direction& dir);

private:
    int row;
    int col;
};

#endif 
