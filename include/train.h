// Copyright 2022 NNTU-CS
#ifndef TRAIN_H
#define TRAIN_H

#include <vector>

class Train {
private:
    struct Car {
        bool light;
        Car *next;
        Car *prev;
    };

    Car *first;
    int countOp;

public:
    Train();
    ~Train();

    void addCar(bool light);
    int getLength(); // реализуем внутри
    int getOpCount() { return countOp; }
};

#endif // TRAIN_H
