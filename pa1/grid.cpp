#include "grid.h"
#include "grid_given.cpp"

// PA1 functions


/**
 * Destroys the current Grid. This function should ensure that
 * memory does not leak on destruction of a grid.
 */
 Grid::~Grid(){ /*your code here*/
   for (int i=0; i<bheight_; i++) {
     for (int j = 0; j < bwidth_; i++) {
       // if (* headOfRow_[i] != NULL) {
         Node * head = headOfRow_[i];
         headOfRow_[i] = head->right;
         delete head;
       // }
     }
   }
 }

/**
 * Rotate row r (row 0 is the first) by count positions.
 * If row r is ABCDE (left to right) in grid g then row r
 * in grid g should be DEABC after the call g.rotateR(r, 2).
 * Rotate headOfCol_ if necessary.
 */
void Grid::rotateR(int r, int count) { /* your code here */
  for (int i = 0; i<count; i++) {
    headOfRow_[r] = headOfRow_[r]->left;
    if (r == 0) {
      for (unsigned int i = 0; i<numCols-1; i++) {
        Node * curr = headOfCol_[i];
        headOfCol_[i] = curr->left;
      }
    }
    Node * curr = headOfRow_[r];
    for (unsigned int i = 0; i<numCols-2; i++) {
      //Node * curr = headOfRow_[r];
      curr->up = curr->right->up;
      curr->down = curr->right->down;
      curr = curr->right;
    }
    Node * last = headOfRow_[r]->left;
    if (r == 0) {
      last->up = headOfRow_[numRows-1]->left;
    } else {
      last->up = headOfRow_[r-1]->left;
    }
    if (numRows-1 >= r+1) {
      last->down = headOfRow_[r+1]->left;
    } else {
      last->down = headOfRow_[0]->left;
    }
  }
}

/**
 * Rotate column c (column 0 is the first) by count positions.
 * If column c is ABCDE (top to bottom) in grid g then column c
 * in grid g should be DEABC after the call g.rotateC(c, 2).
 * Rotate headOfRow_ if necessary.
 */
void Grid::rotateC(int c, int count) { /* your code here */
  for (int i = 0; i<count; i++) {
    headOfCol_[c] = headOfCol_[c]->up;
    if (c == 0) {
      for (int i = 0; i<bheight_; i++) {
        Node * curr = headOfRow_[i];
        headOfRow_[i] = curr->left;
      }
    }
    for (int i = 0; i<bheight_-1; i++) {
      Node * curr = headOfCol_[c];
      curr->left = curr->down->left;
      curr->right = curr->down->right;
      curr = curr->down;
    }
    Node * last = headOfCol_[c]->up;
    last->left = headOfCol_[c-1];
    if (headOfCol_.size() - 1 >= c+1) {
      last->right = headOfCol_[c+1];
    }
  }
}


/**
 * Destroys all dynamically allocated memory associated with the
 * current Grid class. Clears headOfRow_ and headOfCol_ vectors.
 * Sets bwidth_, bheight_ to zero.
 * After clear() the grid represents an empty grid.
 */
void Grid::clear() { /*your code here*/
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

}
