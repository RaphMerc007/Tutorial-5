#ifndef RGB_H
#define RGB_H
#include "defs.h"

class RGB {
  private:
    int r;
    int g;
    int b;

  public:
    RGB(int r, int g, int b):
      r((r > 0 && r < 256) ? r : 0),
      g((g > 0 && g < 256) ? g : 0),
      b((b > 0 && b < 256) ? b : 0) {}
    RGB(CuColour colour):
      r((colour >> 16) & 0xFF),
      g((colour >> 8) & 0xFF),
      b(colour & 0xFF) {}
    RGB():r(0),g(0),b(0) {}

    int getR() const { return r; }
    int getG() const { return g; }
    int getB() const { return b; }
    CuColour getColour() const;
    
    void setR(int r) { this->r = (r > 0 && r < 256) ? r : 0; }
    void setG(int g) { this->g = (g > 0 && g < 256) ? g : 0; }
    void setB(int b) { this->b = (b > 0 && b < 256) ? b : 0; }

    void setColour(CuColour cuColour);
    void print() const;

    static RGB WHITE() {
      RGB rgb(255, 255, 255);
      return rgb;
    }
    static RGB BLACK() {
      RGB rgb(0, 0, 0);
      return rgb;
    }
    static RGB RED() {
      RGB rgb(255, 0, 0);
      return rgb;
    } 
    static RGB GREEN() {
      RGB rgb(0, 255, 0);
      return rgb;
    }
    static RGB BLUE() {
      RGB rgb(0, 0, 255);
      return rgb;
    }  
};

#endif