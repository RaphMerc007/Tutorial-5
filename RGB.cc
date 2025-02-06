#include "defs.h"
#include "RGB.h"
#include <iostream>
using namespace std;

void RGB::setColour(CuColour cuColour){
   r = (cuColour >> 16) & 0xFF;
   g = (cuColour >> 8) & 0xFF;
   b = cuColour & 0xFF;
}

CuColour RGB::getColour() const{
   return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
} 

void RGB::print()const{
   cout << "RGB(" << r << ", " << g << ", " << b << ")" << endl;
}