#ifndef POSITION_H
#define POSITION_H
#include <string>

using namespace std;

class Position {
    int row;
    int col;

public:
    Position(int row , int col);
    Position() : row(0), col(0) {}
    int getRow() const;
    int getCol() const;
    bool operator==(const Position& other) const;
    Position operator+(const string& dir);
};

#endif 
