#ifndef _MINIMAX_H
#define _MINIMAX_H
#include <iostream>

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  int level;

  
  Node (int *leafValues, int level);
  ~Node();
};


int maximin(Node &node);

int minimax(Node &node);

#endif
