// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>
Train::Train() : countOp(0), first(nullptr) {}
Train::~Train() {
  if (!first) return;
  Car* current = first->next;
  while (current != first) {
    Car* temp = current;
    current = current->next;
    delete temp;
  }
  delete first;
}
void Train::addCar(bool light) {
  Car* newCar = new Car{ light, nullptr, nullptr };
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  bool initialLight = first->light;
  first->light = true;
  Car* current = first->next;
  int length = 1;
  while (true) {
    countOp++;
    if (current->light) {
      current->light = false;
      for (int i = 0; i < length; ++i) {
        current = current->prev;
        countOp++;
      }
      if (!current->light) {
        break;
      }
      length = 1;
      current = current->next;
    } else {
      current = current->next;
      length++;
    }
  }
  first->light = initialLight;
  return length;
}
int Train::getOpCount() {
  return countOp;
}
