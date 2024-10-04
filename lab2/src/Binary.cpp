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

Binary::Binary() : bSize(1), bData(new unsigned char{0}) {}

Binary::Binary(size_t size, unsigned char value) {
    if (size == 0) {
        throw InvalidSizeException();
    }
    bSize = size;
    bData = new unsigned char[size];
    unsigned char numericValue = value - '0'; 

    if (numericValue != 0 && numericValue != 1) {
        throw InvalidDigitException();
    }
    
    for (size_t i = 0; i < size; ++i) {
        bData[i] = numericValue;
    }
}

Binary::Binary(const std::initializer_list<unsigned char>& values) {
    size_t i = 0;
    int flag = 0;
    for (unsigned char digit : values) {
        if (digit == '1') break;
        ++flag;
    }
    bSize = values.size() - flag;
    bData = new unsigned char[bSize];
    for (unsigned char digit : values) {
        if (flag == 0) {
            unsigned char numericValue = digit - '0';
            if (numericValue != 0 && numericValue != 1) {
                throw InvalidDigitException();
            }
            bData[i++] = numericValue;
        } else {
            --flag;
        }
    }
}

Binary::Binary(const std::string& binaryString) {
    std::string cleanedBinaryString = removeLeadingZeros(binaryString);
    validateBinaryString(cleanedBinaryString);
    bSize = cleanedBinaryString.size();
    bData = new unsigned char[bSize];
    for (size_t i = 0; i < bSize; ++i) {
        bData[i] = cleanedBinaryString[i] - '0';
    }
}

Binary::Binary(const Binary& other) {
    bSize = other.bSize;
    bData = new unsigned char[bSize];
    for (size_t i = 0; i < bSize; ++i) {
        bData[i] = other.bData[i];
    }
}

Binary::Binary(Binary&& other) noexcept {
    bSize = other.bSize;
    bData = other.bData;

    other.bSize = 0;
    other.bData = nullptr;
}

Binary::~Binary() noexcept {
    if (bSize > 0) {
        delete[] bData;
        bData = nullptr;
        bSize = 0;
    }
}

std::ostream& operator<<(std::ostream& os, const Binary& binary) {
    for (size_t i = 0; i < binary.bSize; ++i) {
        os << static_cast<int>(binary.bData[i]);
    }
    return os;
}

Binary& Binary::operator=(const Binary& other) {
    if (this == &other) {
        return *this;
    }
    delete[] bData;
    bSize = other.bSize;
    bData = new unsigned char[bSize];
    for (size_t i = 0; i < bSize; ++i) {
        bData[i] = other.bData[i];
    }
    return *this;
}

Binary Binary::operator+(const Binary& other) const {
    unsigned long long decimal1 = 0;
    for (size_t i = 0; i < bSize; ++i) {
        decimal1 = decimal1 * 2 + bData[i];
    }

    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.bSize; ++i) {
        decimal2 = decimal2 * 2 + other.bData[i];
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
    for (size_t i = 0; i < bSize; ++i) {
        decimal1 = decimal1 * 2 + bData[i];
    }

    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.bSize; ++i) {
        decimal2 = decimal2 * 2 + other.bData[i];
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
    if (bSize != other.bSize) return false;
    for (size_t i = 0; i < bSize; ++i) {
        if (bData[i] != other.bData[i]) return false;
    }
    return true;
}

bool Binary::operator!=(const Binary& other) const {
    return !(*this == other);
}

bool Binary::operator<(const Binary& other) const {
    if (bSize < other.bSize) return true;
    if (bSize > other.bSize) return false;
    for (size_t i = 0; i < bSize; ++i) {
        if (bData[i] < other.bData[i]) return true;
        if (bData[i] > other.bData[i]) return false;
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
    return bSize;
}
