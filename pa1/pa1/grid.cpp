#include "grid.h"
#include "grid_given.cpp"

// PA1 functions


/**
 * Destroys the current Grid. This function should ensure that
 * memory does not leak on destruction of a grid.
 */
 Grid::~Grid(){ /*your code here*/
   clear();
 }

/**
 * Rotate row r (row 0 is the first) by count positions.
 * If row r is ABCDE (left to right) in grid g then row r
 * in grid g should be DEABC after the call g.rotateR(r, 2).
 * Rotate headOfCol_ if necessary.
 */
 void Grid::rotateR(int r, int count) { /* your code here */
   if (r > numRows()-1 || r < 0) {
     r = r % numRows();
   }
   for (int i = 0; i<count; i++) {
     // headOfRow_[r] = headOfRow_[r]->left;
     if (r == 0) {
       for (int i = 0; i<numCols(); i++) {
         Node * curr = headOfCol_[i];
         headOfCol_[i] = curr->left;
       }
     }
     Node * curr = headOfRow_[r];
     Node * up = headOfRow_[r]->up;
     Node * down = headOfRow_[r]->down;
     for (int i = 0; i<numCols()-1; i++) {
       curr->up = curr->right->up;
       curr->down = curr->right->down;

       up->down = up->down->left;
       down->up = down->up->left;

       curr = curr->right;
       up = up->right;
       down = down->right;
     }
     Node * last = headOfRow_[r]->left;
     Node * lastUp = headOfRow_[r]->left->up;
     Node * lastDown = headOfRow_[r]->left->down;

     last->up = last->up->right;
     last->down = last->down->right;

     lastUp->down = lastUp->down->left;
     lastDown->up = lastDown->up->left;

     headOfRow_[r] = headOfRow_[r]->left;
   }
 }

/**
 * Rotate column c (column 0 is the first) by count positions.
 * If column c is ABCDE (top to bottom) in grid g then column c
 * in grid g should be DEABC after the call g.rotateC(c, 2).
 * Rotate headOfRow_ if necessary.
 */
 void Grid::rotateC(int c, int count) { /* your code here */
   if (c > numCols()-1 || c < 0) {
     c = c % numCols();
   }
   for (int i = 0; i<count; i++) {
     if (c == 0) {
       for (int i = 0; i<numRows(); i++) {
         Node * curr = headOfRow_[i];
         headOfRow_[i] = curr->up;
       }
     }
     Node * curr = headOfCol_[c];
     Node * left = headOfCol_[c]->left;
     Node * right = headOfCol_[c]->right;
     for (int i = 0; i<numRows()-1; i++) {
       curr->left = curr->down->left;
       curr->right = curr->down->right;

       left->right = left->right->up;
       right->left = right->left->up;

       curr = curr->down;
       left = left->down;
       right = right->down;
     }
     Node * last = headOfCol_[c]->up;
     Node * lastLeft = headOfCol_[c]->up->left;
     Node * lastRight = headOfCol_[c]->up->right;

     last->left = last->left->down;
     last->right = last->right->down;

     lastLeft->right = lastLeft->right->up;
     lastRight->left = lastRight->left->up;


     headOfCol_[c] = headOfCol_[c]->up;
   }
 }


/**
 * Destroys all dynamically allocated memory associated with the
 * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
 * Sets bwidth_, bheight_ to zero.
 * After clear() the grid represents an empty grid.
 */
void Grid::clear() { /*your code here*/
  for (int i=0; i < numRows(); i++) {
    for (int j = 0; j < numCols()-1; j++) {
      Node * head = headOfRow_[i];
      headOfRow_[i] = headOfRow_[i]->right;
      delete head;
    }
    delete headOfRow_[i];
  }
  headOfRow_.clear();
  headOfCol_.clear();
  bwidth_ = 0;
  bheight_= 0;
}


/**
 * Makes the current Grid a copy of the "other" Grid.
 * The dimensions should be the same.  The Nodes should
 * contain the same blocks, but the Nodes should be newly
 * allocated. This function is used in both the copy
 * constructor and the assignment operator for Grids.
 */
void Grid::copy(Grid const& other) { /*your code here*/
  clear();

  this->bheight_ = other.bheight();
  this->bwidth_ = other.bwidth();
  int numCols = other.numCols();
  int numRows = other.numRows();

  vector <vector <Node *>> copyA;
  for (int j = 0; j < numRows; j++) {
    vector <Node *> temp;

    Node * n = other.headOfRow_[j];

    for (int i = 0; i < numCols; i++) {
      Node * p = new Node(n->block);
      temp.push_back(p);
      n = n->right;
    }
    copyA.push_back(temp);
  }
  for (int j = 0; j < numRows; j++) {
    for (int i = 0; i < numCols; i++) {
      Node * p = copyA[j][i];

      p->up = copyA[(j == 0) ? numRows-1 : j-1][i];
      p->down = copyA[(j == numRows-1) ? 0 : j+1][i];
      p->left = copyA[j][(i == 0) ? numCols-1 : i-1];
      p->right = copyA[j][(i == numCols-1) ? 0 : i+1];
    }
  }
  for (int j = 0; j < numRows; j++) {
    headOfRow_.push_back(copyA[j][0]);
  }
  for (int i = 0; i < numCols; i++) {
    headOfCol_.push_back(copyA[0][i]);
  }
}
