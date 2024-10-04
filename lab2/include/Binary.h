#pragma once
#include <initializer_list>

#include <iostream>
#include <stdexcept>
#include <string>

class Binary {
public:
    Binary();
    Binary(size_t size, unsigned char value = 0);
    Binary(const std::initializer_list<unsigned char>& values);
    Binary(const std::string& binaryString);
    Binary(const Binary& other);
    Binary(Binary&& other) noexcept;
    ~Binary() noexcept;

    Binary& operator=(const Binary& other);
    Binary operator+(const Binary& other) const;
    Binary operator-(const Binary& other) const;
    Binary& operator+=(const Binary& other);
    Binary& operator-=(const Binary& other);

    bool operator==(const Binary& other) const;
    bool operator!=(const Binary& other) const;
    bool operator<(const Binary& other) const;
    bool operator>(const Binary& other) const;
    bool operator<=(const Binary& other) const;
    bool operator>=(const Binary& other) const;

    size_t getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const Binary& binary);

private:
    size_t b_size;
    unsigned char* b_data;
};
class InvalidDigitException : public std::invalid_argument {
public:
    InvalidDigitException() : std::invalid_argument("Invalid binary string") {}
};

class InvalidSizeException : public std::invalid_argument {
public:
    InvalidSizeException() : std::invalid_argument("Size can't dt zero") {}
};

class SubtractionUnderflowException : public std::logic_error {
public:
    SubtractionUnderflowException() : std::logic_error("Subtraction underflow: the result of the subtraction is negative") {}
};
