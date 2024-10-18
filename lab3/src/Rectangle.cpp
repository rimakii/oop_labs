#include "../include/Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}

std::pair<double, double> Rectangle::center() const {
    return {(x1 + x2) / 2, (y1 + y2) / 2};
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")";
}

void Rectangle::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2;
}

Rectangle::operator double() const {
    return std::abs((x2 - x1) * (y2 - y1));
}

bool Rectangle::operator==(const Rectangle& other) const {
    return x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2;
}

Rectangle::Rectangle(const Rectangle& other)
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2) {
    other.x1 = other.y1 = other.x2 = other.y2 = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        x1 = other.x1;
        y1 = other.y1;
        x2 = other.x2;
        y2 = other.y2;
        other.x1 = other.y1 = other.x2 = other.y2 = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle: (" << rect.x1 << ", " << rect.y1 << ") - (" << rect.x2 << ", " << rect.y2 << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect) {
    is >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
    return is;
}