#pragma once
#include "Figure.h"

class Array {
public:
    Array(size_t initialSize = 10);
    ~Array();

    void add(Figure* figure);
    void remove(size_t index);
    void printAll() const;
    double totalArea() const;

private:
    Figure** figures;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity);
    bool isValidIndex(size_t index) const;
};

