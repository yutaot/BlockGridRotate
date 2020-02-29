#include "block.h"
#include <vector>
#include <iostream>


/**
 * Returns the width of the block.
 */
int Block::width() const{/*your code here*/
  return data.size();
}

/**
 * Returns the height of the block.
 */
int Block::height() const{/*your code here*/
  return data[0].size();
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
  // PNG image = im;
  // int posx = x;
  // int posy = y;

  vector <std::vector<HSLAPixel>> block;
  block.resize(height, std::vector<HSLAPixel>(width));
  data = block;
  // vector <HSLAPixel> vertical;
  // vertical.assign(height);
  // vector <HSLAPixel> horizontal;
  // horizontal.assign(width, vertical);
  // data = horizontal;
}

/**
 * Draws the block at position (x,y) in the image im
 */
void Block::render(PNG & im, int x, int y) const {/*your code here*/
  Block(im, x, y, width(), height());
}

/**
 * Changes the saturation of every pixel in the block to 0,
 * which removes the color, leaving grey.
 */
void Block::greyscale() {/*your code here*/
  for (int x = 0; x < width(); x++) {
    for (int y = 0; y < height(); y++) {
      HSLAPixel * pixel = data[x][y];
      pixel->s = 0;
    }
  }
}
