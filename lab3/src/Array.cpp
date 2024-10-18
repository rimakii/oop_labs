#include "../include/Array.h"
#include <iostream>

Array::Array(size_t initialSize) : size(0), capacity(initialSize) {
    figures = new Figure*[capacity];
}

Array::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

void Array::add(Figure* figure) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    figures[size++] = figure;
}

void Array::remove(size_t index) {
    if (isValidIndex(index)) {
        delete figures[index];
        for (size_t i = index; i < size - 1; ++i) {
            figures[i] = figures[i + 1];
        }
        --size;
    }
}

void Array::printAll() const {
    for (size_t i = 0; i < size; ++i) {
        figures[i]->print(std::cout);
        std::cout << " Center: (" << figures[i]->center().first << ", " << figures[i]->center().second << ")";
        std::cout << " Area: " << static_cast<double>(*figures[i]) << std::endl;
    }
}

double Array::totalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*figures[i]);
    }
    return total;
}

void Array::resize(size_t newCapacity) {
    Figure** newFigures = new Figure*[newCapacity];
    for (size_t i = 0; i < size; ++i) {
        newFigures[i] = figures[i];
    }
    delete[] figures;
    figures = newFigures;
    capacity = newCapacity;
}

bool Array::isValidIndex(size_t index) const {
    return index < size;
}