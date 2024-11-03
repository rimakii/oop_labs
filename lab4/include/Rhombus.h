#pragma once
#include "Figure.h"

template <Scalar T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4);

    Point<T> center() const override;
    double area() const override;
};

template <Scalar T>
Trapezoid<T>::Trapezoid(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
    this->addVertex(std::make_unique<Point<T>>(x1, y1));
    this->addVertex(std::make_unique<Point<T>>(x2, y2));
    this->addVertex(std::make_unique<Point<T>>(x3, y3));
    this->addVertex(std::make_unique<Point<T>>(x4, y4));
}

template <Scalar T>
Point<T> Trapezoid<T>::center() const {
    T center_x = (this->vertices[0].x + this->vertices[1].x + this->vertices[2].x + this->vertices[3].x) / 4;
    T center_y = (this->vertices[0].y + this->vertices[1].y + this->vertices[2].y + this->vertices[3].y) / 4;
    return {center_x, center_y};
}

template <Scalar T>
double Trapezoid<T>::area() const {
    T x1 = this->vertices[0].x, y1 = this->vertices[0].y;
    T x2 = this->vertices[1].x, y2 = this->vertices[1].y;
    T x3 = this->vertices[2].x, y3 = this->vertices[2].y;
    T x4 = this->vertices[3].x, y4 = this->vertices[3].y;

    double area = 0.5 * std::abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - (y1*x2 + y2*x3 + y3*x4 + y4*x1));
    return area;
}