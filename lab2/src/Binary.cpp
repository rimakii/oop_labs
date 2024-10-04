#include "../include/Binary.h"
#include <iostream>
#include <stdexcept>
#include <string>

void validateBinaryString(const std::string& binaryString) {
    for (char digit : binaryString) {
        if (digit != '0' && digit != '1') {
            throw InvalidDigitException();
        }
    }
}

std::string removeLeadingZeros(const std::string& binaryString) {
    size_t pos = binaryString.find_first_not_of('0');
    if (pos == std::string::npos) {
        return "0"; 
    }
    return binaryString.substr(pos);
}

Binary::Binary() : b_size(1), b_data(new unsigned char{0}) {}

Binary::Binary(size_t size, unsigned char value) {
    if (size == 0) {
        throw InvalidSizeException();
    }
    b_size = size;
    b_data = new unsigned char[size];
    unsigned char numericValue = value - '0'; 

    if (numericValue != 0 && numericValue != 1) {
        throw InvalidDigitException();
    }
    
    for (size_t i = 0; i < size; ++i) {
        b_data[i] = numericValue;
    }
}

Binary::Binary(const std::initializer_list<unsigned char>& values) {
    size_t i = 0;
    int flag = 0;
    for (unsigned char digit : values) {
        if (digit == '1') break;
        ++flag;
    }
    b_size = values.size() - flag;
    b_data = new unsigned char[b_size];
    for (unsigned char digit : values) {
        if (flag == 0) {
            unsigned char numericValue = digit - '0';
            if (numericValue != 0 && numericValue != 1) {
                throw InvalidDigitException();
            }
            b_data[i++] = numericValue;
        } else {
            --flag;
        }
    }
}

Binary::Binary(const std::string& binaryString) {
    std::string cleanedBinaryString = removeLeadingZeros(binaryString);
    validateBinaryString(cleanedBinaryString);
    b_size = cleanedBinaryString.size();
    b_data = new unsigned char[b_size];
    for (size_t i = 0; i < b_size; ++i) {
        b_data[i] = cleanedBinaryString[i] - '0';
    }
}

Binary::Binary(const Binary& other) {
    b_size = other.b_size;
    b_data = new unsigned char[b_size];
    for (size_t i = 0; i < b_size; ++i) {
        b_data[i] = other.b_data[i];
    }
}

Binary::Binary(Binary&& other) noexcept {
    b_size = other.b_size;
    b_data = other.b_data;

    other.b_size = 0;
    other.b_data = nullptr;
}

Binary::~Binary() noexcept {
    if (b_size > 0) {
        delete[] b_data;
        b_data = nullptr;
        b_size = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Binary& binary) {
    for (size_t i = 0; i < binary.b_size; ++i) {
        os << static_cast<int>(binary.b_data[i]);
    }
    return os;
}

Binary& Binary::operator=(const Binary& other) {
    if (this == &other) {
        return *this;
    }
    delete[] b_data;
    b_size = other.b_size;
    b_data = new unsigned char[b_size];
    for (size_t i = 0; i < b_size; ++i) {
        b_data[i] = other.b_data[i];
    }
    return *this;
}

Binary Binary::operator+(const Binary& other) const {
    unsigned long long decimal1 = 0;
    for (size_t i = 0; i < b_size; ++i) {
        decimal1 = decimal1 * 2 + b_data[i];
    }

    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.b_size; ++i) {
        decimal2 = decimal2 * 2 + other.b_data[i];
    }

    unsigned long long sumDecimal = decimal1 + decimal2;

    std::string binaryString;
    while (sumDecimal > 0) {
        binaryString = (sumDecimal % 2 == 0 ? "0" : "1") + binaryString;
        sumDecimal /= 2;
    }

    if (binaryString.empty()) {
        binaryString = "0";
    }

    return Binary(binaryString);
}

Binary Binary::operator-(const Binary& other) const {
    if (!(*this >= other)) {
        throw SubtractionUnderflowException();
    }

    unsigned long long decimal1 = 0;
    for (size_t i = 0; i < b_size; ++i) {
        decimal1 = decimal1 * 2 + b_data[i];
    }

    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.b_size; ++i) {
        decimal2 = decimal2 * 2 + other.b_data[i];
    }

    unsigned long long diffDecimal = decimal1 - decimal2;

    std::string binaryString;
    while (diffDecimal > 0) {
        binaryString = (diffDecimal % 2 == 0 ? "0" : "1") + binaryString;
        diffDecimal /= 2;
    }

    if (binaryString.empty()) {
        binaryString = "0";
    }

    return Binary(binaryString);
}

Binary& Binary::operator+=(const Binary& other) {
    *this = *this + other;
    return *this;
}

Binary& Binary::operator-=(const Binary& other) {
    *this = *this - other;
    return *this;
}

bool Binary::operator==(const Binary& other) const {
    if (b_size != other.b_size) return false;
    for (size_t i = 0; i < b_size; ++i) {
        if (b_data[i] != other.b_data[i]) return false;
    }
    return true;
}

bool Binary::operator!=(const Binary& other) const {
    return !(*this == other);
}

bool Binary::operator<(const Binary& other) const {
    if (b_size < other.b_size) return true;
    if (b_size > other.b_size) return false;
    for (size_t i = 0; i < b_size; ++i) {
        if (b_data[i] < other.b_data[i]) return true;
        if (b_data[i] > other.b_data[i]) return false;
    }
    return false;
}

bool Binary::operator>(const Binary& other) const {
    return other < *this;
}

bool Binary::operator<=(const Binary& other) const {
    return (*this < other) || (*this == other);
}

bool Binary::operator>=(const Binary& other) const {
    return (*this > other) || (*this == other);
}

size_t Binary::getSize() const {
    return b_size;
}
