#include "block.h"
#include <vector>
#include <iostream>


/**
 * Returns the width of the block.
 */
int Block::width() const{/*your code here*/
  return data[0].size();
}

/**
 * Returns the height of the block.
 */
int Block::height() const{/*your code here*/
  return data.size();
}

/**
 * Default Block constructor.
 */
Block::Block() {/* nothing */}

/**
 * Useful Block constructor.
 * Makes a block from the rectangle of width by height pixels in im
 * whose upper-left corner is at position (x,y).
 */
Block::Block(PNG & im, int x, int y, int width, int height) {/*your code here*/
  vector <vector<HSLAPixel>> block;
  block.resize(height);
  for (int i = 0; i < height; i++) {
    block[i].resize(width);
  }
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      if (0 <= x+i < im.width() && 0 <= y+j < im.height()) {
        block[j][i] = * im.getPixel(x+i, y+j);
      }
    }
  }
  data = block;
}

/**
 * Draws the block at position (x,y) in the image im
 */
void Block::render(PNG & im, int x, int y) const {/*your code here*/
  for (int i = 0; i < width(); i++) {
    for (int j = 0; j < height(); j++) {
      if (0 <= x+i < im.width() && 0 <= y+j < im.height()) {
        * im.getPixel(x+i, y+j) = data[j][i];
      }
    }
  }
}

/**
 * Changes the saturation of every pixel in the block to 0,
 * which removes the color, leaving grey.
 */
void Block::greyscale() {/*your code here*/
  for (int x = 0; x < width(); x++) {
    for (int y = 0; y < height(); y++) {
      HSLAPixel * pixel = & data[y][x];
      pixel->s = 0;
    }
  }
}
