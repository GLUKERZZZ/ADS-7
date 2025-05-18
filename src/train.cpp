// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}
Train::~Train() {
  if (!first) return;
  Car* curr = first;
  do {
    Car* nextCar = curr->next;
    delete curr;
    curr = nextCar;
  } while (curr != first);
  first = nullptr;
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
  Car* current = first;
  int length = 0;
  do {
    length++;
    current = current->next;
  } while (current != first);
  return length;
}
