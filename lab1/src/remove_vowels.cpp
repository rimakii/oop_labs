#include "../include/remove_vowels.h"

std::string removeVowels(const std::string& str) {
    const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    const int vowelsCount = sizeof(vowels) / sizeof(vowels[0]);
    std::string result;

    for (char ch : str) {
        bool isVowel = false;
        for (int i = 0; i < vowelsCount; ++i) {
            if (ch == vowels[i]) {
                isVowel = true;
                break;
            }
        }
        if (!isVowel) {
            result += ch;
        }
    }

    return result;
}