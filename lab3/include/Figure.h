#pragma once
#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> center() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual operator double() const = 0;
};
