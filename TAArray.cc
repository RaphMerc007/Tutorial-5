#include "TAArray.h"
#include "TextArea.h"
#include <iostream>

using namespace std;

TAArray::TAArray() {
  this->size = 0;
  data = new TextArea*[MAX_COMPONENTS];
}

TAArray::~TAArray() {
  for (int i = 0; i < size+1; i++) {
		delete data[i];
  }
  delete[] data;
}

int TAArray::getSize() const {
  return size;
}

void TAArray::add(TextArea* ta) {
  add(ta, size);
}

bool TAArray::add(TextArea* other, int index) {
  if (index < 0 || index > size || size >= MAX_COMPONENTS) {
  	return false;
  }
  
  for (int i = size; i > index; i--) {
    data[i] = data[i - 1];
  }

  data[index] = other;
  size++;
	return true;
}

TextArea* TAArray::get(string id) const {
  for (int i = 0; i < size; i++) {
    if (data[i]->getId() == id) {
      return data[i];
    }
  }
  return nullptr;
}

TextArea* TAArray::get(int index) const {
  if (index < 0 || index >= size) {
    return nullptr;
  }
  return data[index];
}

TextArea* TAArray::remove(int index) {
  if (index < 0 || index >= size) {
    return nullptr;
  }
  TextArea* temp = data[index];
	delete data[index];
  for (int i = index; i < size - 1; i++) {
    data[i] = data[i + 1];
  }
	size--;
  return temp;
}

TextArea* TAArray::remove(string id) {
  for (int i = 0; i < size; i++) {
    if (data[i]->getId() == id) {
      return remove(i);
    }
  }
  return nullptr;
}