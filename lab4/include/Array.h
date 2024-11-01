#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t size;
    size_t capacity;

public:
    Array(size_t initial_capacity = 10);

    void push_back(T&& item);
    void remove(size_t index);

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t get_size() const;
    double total_area() const; // ????? ??????? ??? ?????????? ????? ???????

private:
    void resize(size_t new_capacity);
};

// ??????????? ??????? ????? ? ???????????? ?????
template <typename T>
Array<T>::Array(size_t initial_capacity) : size(0), capacity(initial_capacity) {
    data = std::make_shared<T[]>(initial_capacity);
}

template <typename T>
void Array<T>::push_back(T&& item) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = std::move(item);
}

template <typename T>
void Array<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
size_t Array<T>::get_size() const {
    return size;
}

template <typename T>
double Array<T>::total_area() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*data[i]);
    }
    return total;
}

template <typename T>
void Array<T>::resize(size_t new_capacity) {
    auto new_data = std::make_shared<T[]>(new_capacity);
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    data = new_data;
    capacity = new_capacity;
}