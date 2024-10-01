#include "minimax.h"
using namespace std;

int leafIndex = 0;

Node::Node (int * leafValues, int level) : level{level} {
  if ( this->level < 2 ){
    this->left = new Node{leafValues, (this->level + 1)};
    this->right = new Node{leafValues, (this->level + 1)};
  } else {
    this->value = leafValues[leafIndex++];
  }
}

int minimax(Node &node){
  int leftEval = maximin(*node.left);
  int rightEval = maximin(*node.right);

  //Assign result of max evaluation
  node.value = max(leftEval, rightEval);
  return node.value;
}

int maximin(Node &node){
  int leftEval = minimax(*node.left);
  int rightEval = minimax(*node.right);

  //Assign result of min evaluation
  node.value = min(leftEval, rightEval);
  return node.value;
}

Node::~Node() {
	delete this->left;
	delete this->right;
}
