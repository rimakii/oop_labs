#pragma once
#include "Figure.h"
#include <cmath>

template <Scalar T>
class Rhombus : public Figure<T> {
public:
    Rhombus(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4);

    Point<T> center() const override;
    double area() const override;
};

template <Scalar T>
Rhombus<T>::Rhombus(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
    this->addVertex(std::make_unique<Point<T>>(x1, y1));
    this->addVertex(std::make_unique<Point<T>>(x2, y2));
    this->addVertex(std::make_unique<Point<T>>(x3, y3));
    this->addVertex(std::make_unique<Point<T>>(x4, y4));
}

template <Scalar T>
Point<T> Rhombus<T>::center() const {
    T center_x = (this->vertices[0].x + this->vertices[2].x) / 2;
    T center_y = (this->vertices[0].y + this->vertices[2].y) / 2;
    return {center_x, center_y};
}

template <Scalar T>
double Rhombus<T>::area() const {
    T d1 = std::sqrt(std::pow(this->vertices[1].x - this->vertices[3].x, 2) + std::pow(this->vertices[1].y - this->vertices[3].y, 2));
    T d2 = std::sqrt(std::pow(this->vertices[0].x - this->vertices[2].x, 2) + std::pow(this->vertices[0].y - this->vertices[2].y, 2));
    return 0.5 * d1 * d2;
}
