#include <iostream>
#include <string>
#include "include/Binary.h"
int main() {
    
    size_t lengthNumber;
    std::cout << "Enter the length of the first number: ";
    std::cin >> lengthNumber;

    unsigned char defaultValue;
    std::cout << "Enter the default value for the first number (0 or 1): ";
    std::cin >> defaultValue;

    Binary number1;

    try {
        number1 = Binary(lengthNumber, defaultValue);
        std::cout << "First number: " << number1 << std::endl;
    } catch (const InvalidDigitException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const MemoryAllocationException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const InvalidSizeException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "Enter 4 bits for the second number (0 or 1): ";
    unsigned char arrayNumbers[4];
    for (int i = 0; i < 4; ++i) {
        std::cin >> arrayNumbers[i];
    }

    Binary number2;
    try {
        number2 = Binary({arrayNumbers[0], arrayNumbers[1], arrayNumbers[2], arrayNumbers[3]});
        std::cout << "Second number: " << number2 << std::endl;
    } catch (const InvalidDigitException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const MemoryAllocationException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    std::string binaryString;
    std::cout << "Enter a binary string (only '0' and '1'): ";
    std::cin >> binaryString;

    Binary number3;
    try {
        number3 = Binary(binaryString);
        std::cout << "Third number: " << number3 << std::endl;
    } catch (const InvalidDigitException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const MemoryAllocationException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    
    Binary sumResult = number3;
    
    sumResult += number2;

    std::cout << "Sum of Number 1 + Number 2: " << sumResult << std::endl;

    Binary subResult = number3;
    try {
        subResult -= number2;
        std::cout << "Difference of Number 3 - Number 2: " << subResult << std::endl;
    } catch (const SubtractionUnderflowException& e) {
        std::cerr << e.what() << std::endl;
    }

    Binary copyOfNumber1 = number1;
    std::cout << "Copy of Number 1: " << copyOfNumber1 << std::endl;

    Binary movedNumber = std::move(number2);
    std::cout << "Moved Number 2: " << movedNumber << std::endl;

    std::cout << "Comparison: " << std::endl;
    std::cout << "Number 1 == Copy of Number 1: " << (number1 == copyOfNumber1) << std::endl;
    std::cout << "Number 1 < Number 3: " << (number1 < number3) << std::endl;
    std::cout << "Number 3 > Number 1: " << (number3 > number1) << std::endl;
    
    return 0;
    
}