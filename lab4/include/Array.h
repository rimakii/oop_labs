#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t size;
    size_t capacity;

    void increaseCapacity() {
        size_t newCapacity = capacity * 2;
        std::shared_ptr<T[]> newData(new T[newCapacity], std::default_delete<T[]>());
        
        for (size_t i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]); 
        }
        
        data = std::move(newData);
        capacity = newCapacity;
    }

public:
    Array(size_t initialCapacity = 5) : size(0), capacity(initialCapacity) {
        data = std::shared_ptr<T[]>(new T[capacity], std::default_delete<T[]>());
    }

    void add(T element) {
        if (size >= capacity) {
            increaseCapacity();
        }
        data[size++] = std::move(element);
    }

    void remove(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = std::move(data[i + 1]);
            }
            --size;
        }
    }

    double totalArea() const {
        double total = 0;
        for (size_t i = 0; i < size; ++i) {
            if (data[i]) {
                total += data[i]->area();
            }
        }
        return total;
    }

    void printAll() const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << "  Center: " << data[i]->center() << "\n";
            std::cout << "  Area: " << data[i]->area() << "\n";
            std::cout << "  Vertices:\n";
             data[i]->printVertices();
        }
    }
}

    size_t getSize() const {
        return size;
    }
};