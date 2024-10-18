#pragma once
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus() = default;
    Rhombus(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    bool operator==(const Rhombus& other) const;
    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    operator double() const override;
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& rhombus);
    friend std::istream& operator>>(std::istream& is, Rhombus& rhombus);

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
};

 