#ifndef POSITION_H
#define POSITION_H

using namespace std;

class Position {
    int row;
    int col;

public:
    Position(int row , int col);
    int getRow();
    int getCol();
    bool operator==(const Position& other) const;
    Position operator+(const string& dir);
};

#endif 
