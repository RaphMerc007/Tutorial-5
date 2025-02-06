#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"
#include <iostream>

using namespace std;

class TAArray {
  private:
    int size;
    TextArea** data;
    
  public:
    TAArray();
    ~TAArray();
    
    int getSize() const;
    bool isEmpty() const;
    void add(TextArea* ta);
    bool add(TextArea* other, int index);
    TextArea* get(string id) const;
    TextArea* get(int index) const;
    TextArea* remove(int index);
    TextArea* remove(string id);
};

#endif 