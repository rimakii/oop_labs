#include "../include/Binary.h"
#include <iostream>
#include <stdexcept>
#include <string>


unsigned char* allocateMemory(size_t size) {
    unsigned char* ptr = new(std::nothrow) unsigned char[size]{0};
    if (!ptr) {
        throw MemoryAllocationException();
    }
    return ptr;
}

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
        return "0"; // ???? ?????? ??????? ?????? ?? ?????, ?????????? "0"
    }
    return binaryString.substr(pos);
}

Binary::Binary() : b_size(1), data(allocateMemory(1)) {
    data[0] = 0;
}

Binary::Binary(size_t size, unsigned char value) {
    unsigned char numericValue = value - '0'; // ??????????? ?????? ? ?????
    if (numericValue != 0 && numericValue != 1) {
        throw InvalidDigitException();
    }
    if (numericValue == 0){
        b_size = 1;
        data = allocateMemory(1);
        data[0] = 0;
    }
    else{
        b_size = size;
        data = allocateMemory(size);
        for (size_t i = 0; i < size; ++i) {
            data[i] = numericValue;
        }
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
    data = allocateMemory(b_size);
    for (unsigned char digit : values) {
        if (flag == 0){
            unsigned char numericValue = digit - '0'; // ??????????? ?????? ? ?????
            if (numericValue != 0 && numericValue != 1) {
                throw InvalidDigitException();
            }
            data[i++] = numericValue;
        }
        else --flag;
    }
}

Binary::Binary(const std::string& binaryString) : b_size(binaryString.size()), data(allocateMemory(binaryString.size())) {
    std::string cleanedBinaryString = removeLeadingZeros(binaryString);
    validateBinaryString(cleanedBinaryString); // ???????? ?????? ????? ??????????????
    b_size = cleanedBinaryString.size();
    data = allocateMemory(b_size);
    for (size_t i = 0; i < b_size; ++i) {
        data[i] = cleanedBinaryString[i] - '0';
    }
}

Binary::Binary(const Binary& other) : b_size(other.b_size), data(allocateMemory(other.b_size)) {
    for (size_t i = 0; i < b_size; ++i) {
        data[i] = other.data[i];
    }
}

Binary::Binary(Binary&& other) noexcept : b_size(0), data(nullptr) {
    b_size = other.b_size;
    data = other.data;
    other.b_size = 0;
    other.data = nullptr;
}

Binary::~Binary() noexcept {
    delete[] data;
    data = nullptr;
    b_size = 0;
}
// ?????????? ????????? ??????
std::ostream& operator<<(std::ostream& os, const Binary& binary) {
    for (size_t i = 0; i < binary.b_size; ++i) {
        os << static_cast<int>(binary.data[i]);
    }
    return os;
}
Binary& Binary::operator=(const Binary& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;
    b_size = other.b_size;
    data = new unsigned char[b_size];

    for (size_t i = 0; i < b_size; ++i) {
        data[i] = other.data[i];
    }

    return *this;
}

Binary Binary::operator+(const Binary& other) const {
    // ??????????? ??????? ???????? ????? ? ??????????
    unsigned long long decimal1 = 0;
    for (size_t i = 0; i < b_size; ++i) {
        decimal1 = decimal1 * 2 + data[i];
    }

    // ??????????? ?????? ???????? ????? ? ??????????
    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.b_size; ++i) {
        decimal2 = decimal2 * 2 + other.data[i];
    }

    // ?????????? ?????????? ?????
    unsigned long long sumDecimal = decimal1 + decimal2;

    // ??????????? ????????? ??????? ? ???????? ?????
    std::string binaryString;
    while (sumDecimal > 0) {
        binaryString = (sumDecimal % 2 == 0 ? "0" : "1") + binaryString;
        sumDecimal /= 2;
    }

    // ???? ????????? ??????, ??????, ??? ????
    if (binaryString.empty()) {
        binaryString = "0";
    }

    return Binary(binaryString);
}

Binary Binary::operator-(const Binary& other) const {
    if (!(*this >= other)) {
        throw SubtractionUnderflowException();
    }
    // ??????????? ??????? ???????? ????? ? ??????????
    unsigned long long decimal1 = 0;
    for (size_t i = 0; i < b_size; ++i) {
        decimal1 = decimal1 * 2 + data[i];
    }

    // ??????????? ?????? ???????? ????? ? ??????????
    unsigned long long decimal2 = 0;
    for (size_t i = 0; i < other.b_size; ++i) {
        decimal2 = decimal2 * 2 + other.data[i];
    }


    // ???????? ?????????? ?????
    unsigned long long diffDecimal = decimal1 - decimal2;

    // ??????????? ????????? ??????? ? ???????? ?????
    std::string binaryString;
    while (diffDecimal > 0) {
        binaryString = (diffDecimal % 2 == 0 ? "0" : "1") + binaryString;
        diffDecimal /= 2;
    }

    // ???? ????????? ??????, ??????, ??? ????
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
        if (data[i] != other.data[i]) return false;
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
        if (data[i] < other.data[i]) return true;
        if (data[i] > other.data[i]) return false;
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
