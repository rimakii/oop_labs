#pragma once
#include <memory>
#include <iostream>
#include "Point.h"

constexpr size_t MAX_VERTICES = 4; // ???????????? ?????????? ?????? ??? ?????

template <Scalar T>
class Figure {
protected:
    std::unique_ptr<Point<T>[]> vertices;
    size_t num_vertices; // ?????????? ?????? ? ??????

public:
    Figure() : vertices(std::make_unique<Point<T>[]>(MAX_VERTICES)), num_vertices(0) {}
    virtual ~Figure() = default;

    virtual Point<T> center() const = 0;
    virtual double area() const = 0;

    void add_vertex(std::unique_ptr<Point<T>> vertex) {
        if (num_vertices < MAX_VERTICES) {
            vertices[num_vertices++] = std::move(*vertex);
        }
    }

    void print_vertices() const {
        for (size_t i = 0; i < num_vertices; ++i) {
            std::cout << vertices[i] << " ";
        }
        std::cout << std::endl;
    }

    bool operator==(const Figure<T>& other) const {
        if (num_vertices != other.num_vertices) return false;
        for (size_t i = 0; i < num_vertices; ++i) {
            if (vertices[i] != other.vertices[i]) return false;
        }
        return true;
    }

    operator double() const {
        return area();
    }
};

