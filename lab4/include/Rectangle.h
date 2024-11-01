#pragma once
#include "Figure.h"

template <Scalar T>
class Rectangle : public Figure<T> {
public:
    Rectangle(T x1, T y1, T x2, T y2);

    Point<T> center() const override;
    double area() const override;
};

// ??????????? ???????????? ? ??????? ????? ? ???????????? ?????
template <Scalar T>
Rectangle<T>::Rectangle(T x1, T y1, T x2, T y2) {
    this->add_vertex(std::make_unique<Point<T>>(x1, y1));
    this->add_vertex(std::make_unique<Point<T>>(x2, y1));
    this->add_vertex(std::make_unique<Point<T>>(x2, y2));
    this->add_vertex(std::make_unique<Point<T>>(x1, y2));
}

template <Scalar T>
Point<T> Rectangle<T>::center() const {
    T center_x = (this->vertices[0].x + this->vertices[2].x) / 2;
    T center_y = (this->vertices[0].y + this->vertices[2].y) / 2;
    return {center_x, center_y};
}

template <Scalar T>
double Rectangle<T>::area() const {
    T width = this->vertices[1].x - this->vertices[0].x;
    T height = this->vertices[2].y - this->vertices[1].y;
    return std::abs(width * height);
}