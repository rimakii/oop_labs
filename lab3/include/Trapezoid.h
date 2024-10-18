#pragma once
#include "Figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;
    friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid);
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
    
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};
