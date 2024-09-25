#include <iostream>
#include <string>
#include "include/remove_vowels.h"


int main() {

    std::string input{};
    std::cout << "Enter a line:";
    std::getline(std::cin, input);

    std::string output = removeVowels(input);
    
    std::cout << output << std::endl;
    
    return 0;
}