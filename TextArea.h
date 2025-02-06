#ifndef TEXT_AREA_H
#define TEXT_AREA_H
#include "defs.h"
#include "RGB.h"
#include <X11/Xlib.h>
#include <string>
using namespace std;

class TextArea{
   private:
      Rectangle dimensions;
      string text;
      string id;
      RGB fill;
      RGB border;

   public:
      TextArea(int x, int y, int width, int height, string id, string label, RGB fill=RGB::WHITE(), RGB border=RGB::BLACK()){
         dimensions.x = x;
         dimensions.y = y;
         dimensions.width = width;
         dimensions.height = height;
         this->fill = fill;
         this->border = border;
         this->text = label;
         this->id = id;
      }
      TextArea(Rectangle dimensions, string id, string label, RGB fill=RGB::WHITE(), RGB border=RGB::BLACK()){
         this->dimensions = dimensions;
         this->id = id;
         this->text = label;
         this->fill = fill;
         this->border = border;
      }
      TextArea(){
         dimensions = Rectangle();
         id = "TextArea";
         text = "Text Area";
         fill = RGB::WHITE();
         border = RGB::BLACK();
      }
      TextArea(const TextArea& ta){
         dimensions = ta.getDimensions();
         id = ta.getId();
         text = ta.getText();
         fill = ta.getFill();
         border = ta.getBorder();
      }

      Rectangle getDimensions() const{
         return dimensions;
      }
      string getId() const{
         return id;
      }
			string getText() const{
				return text;
			}
      RGB getBorder() const{
         return border;
      }
      RGB getFill() const{
         return fill;
      }
      
      void draw(Display *display, Window win, GC gc, int x, int y) const;
      bool overlaps(const TextArea& ta) const;
      void print() const;
      
};

#endif