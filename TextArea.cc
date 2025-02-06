#include "TextArea.h"
#include <X11/Xlib.h>
#include <iostream>

void TextArea::draw(Display *display, Window win, GC gc, int x, int y) const{
  XSetForeground(display, gc, fill.getColour());
  XDrawRectangle(display, win, gc, x, y, dimensions.width, dimensions.height);
   
	XDrawString(display, win, gc, x, y, text.c_str(), text.length());
}

bool TextArea::overlaps(const TextArea& ta) const {
  return dimensions.overlaps(ta.getDimensions());
}

void TextArea::print() const {
  cout << "TextArea: \t" << id << "\n"
        << "Text: \t\t" << text << "\n"
        << "Fill: \t\t" << fill.getColour() << "\n"
        << "Border: \t" << border.getColour() << endl;
}