#include "../include/Rhombus.h"
#include <cmath>

Rhombus::Rhombus(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}

std::pair<double, double> Rhombus::center() const {
    double cx = (x1 + x2 + x3 + x4) / 4;
    double cy = (y1 + y2 + y3 + y4) / 4;
    return {cx, cy};
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << "), (" << x4 << ", " << y4 << ")";
}

void Rhombus::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

Rhombus::operator double() const {
    double d1 = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double d2 = std::sqrt((x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4));
    return 0.5 * d1 * d2;
}

bool Rhombus::operator==(const Rhombus& other) const {
    return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2;
}

Rhombus::Rhombus(const Rhombus& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {}

Rhombus::Rhombus(Rhombus&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
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

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
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

std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus) {
    os << "Rhombus: (" << rhombus.x1 << ", " << rhombus.y1 << ") - (" << rhombus.x2 << ", " << rhombus.y2 << ") - ("
       << rhombus.x3 << ", " << rhombus.y3 << ") - (" << rhombus.x4 << ", " << rhombus.y4 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Rhombus& rhombus) {
    is >> rhombus.x1 >> rhombus.y1 >> rhombus.x2 >> rhombus.y2 >> rhombus.x3 >> rhombus.y3 >> rhombus.x4 >> rhombus.y4;
    return is;
}