#include "../include/Trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}

std::pair<double, double> Trapezoid::center() const {
    double cx = (x1 + x2 + x3 + x4) / 4;
    double cy = (y1 + y2 + y3 + y4) / 4;
    return {cx, cy};
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << ")";
}

void Trapezoid::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Trapezoid::operator double() const {
    return 0.5 * std::abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) - (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2;
}

Trapezoid::Trapezoid(const Trapezoid& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        x3 = other.x3;
        y3 = other.y3;
        x4 = other.x4;
        y4 = other.y4;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        x3 = other.x3;
        y3 = other.y3;
        x4 = other.x4;
        y4 = other.y4;
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
    os << "Trapezoid: (" << trapezoid.x1 << ", " << trapezoid.y1 << ") - (" << trapezoid.x2 << ", " << trapezoid.y2 << ") - ("
       << trapezoid.x3 << ", " << trapezoid.y3 << ") - (" << trapezoid.x4 << ", " << trapezoid.y4 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.x1 >> trapezoid.y1 >> trapezoid.x2 >> trapezoid.y2 >> trapezoid.x3 >> trapezoid.y3 >> trapezoid.x4 >> trapezoid.y4;
    return is;
}