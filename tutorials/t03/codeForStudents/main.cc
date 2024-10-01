#include <iostream>
#include "minimax.h"

using namespace std;

int main(){
  int leafValues[8] = {-5, 7, -9, 2, -3, 4, 8, 1};
  Node *root = new Node{leafValues, 0};
  root->value = minimax(*root);
  cout << root->value << endl;
  delete root;
  return 0;
}
