#include <gtest/gtest.h>
#include "../include/remove_vowels.h"

TEST(RemoveVowelsTest, BasicTest) {
    std::string input = "This website is for losers LOL!";
    std::string expected = "Ths wbst s fr lsrs LL!";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, EmptyString) {
    std::string input = "";
    std::string expected = "";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, NoVowels) {
    std::string input = "xzs";
    std::string expected = "xzs";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, AllVowels) {
    std::string input = "aeiouyAEIOUY";
    std::string expected = "";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, MixedCase) {
    std::string input = "Hello World!";
    std::string expected = "Hll Wrld!";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, SpecialCharacters) {
    std::string input = "!@#$%^&*()";
    std::string expected = "!@#$%^&*()";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, Numbers) {
    std::string input = "1234567890";
    std::string expected = "1234567890";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, LongString) {
    std::string input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    std::string expected = "Lrm psm dlr st mt, cnscttr dpscng lt.";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, SingleCharacter) {
    std::string input = "a";
    std::string expected = "";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}

TEST(RemoveVowelsTest, MultipleSpaces) {
    std::string input = "   ";
    std::string expected = "   ";
    std::string result = removeVowels(input);
    ASSERT_TRUE(result == expected);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}