#include <gtest/gtest.h>
#include "../include/Binary.h"
#include <sstream>

TEST(BinaryTest, DefaultConstructor) {
    Binary bin;
    ASSERT_TRUE(bin.getSize() == 1);
    std::ostringstream oss;
    oss << bin;
    ASSERT_TRUE(oss.str() == "0");
}

TEST(BinaryTest, SizeValueConstructor) {
    Binary bin(4, '1');
    ASSERT_TRUE(bin.getSize() == 4);
    std::ostringstream oss;
    oss << bin;
    ASSERT_TRUE(oss.str() == "1111");
}

TEST(BinaryTest, InitializerListConstructor) {
    Binary bin({'1', '0', '1', '0'});
    ASSERT_TRUE(bin.getSize() == 4);
    std::ostringstream oss;
    oss << bin;
    ASSERT_TRUE(oss.str() == "1010");
}

TEST(BinaryTest, StringConstructor) {
    Binary bin("1010");
    ASSERT_TRUE(bin.getSize() == 4);
    std::ostringstream oss;
    oss << bin;
    ASSERT_TRUE(oss.str() == "1010");
}

TEST(BinaryTest, CopyConstructor) {
    Binary bin1("1010");
    Binary bin2(bin1);
    ASSERT_TRUE(bin2.getSize() == 4);
    std::ostringstream oss;
    oss << bin2;
    ASSERT_TRUE(oss.str() == "1010");
}

TEST(BinaryTest, MoveConstructor) {
    Binary bin1("1010");
    Binary bin2(std::move(bin1));
    ASSERT_TRUE(bin2.getSize() == 4);
    std::ostringstream oss;
    oss << bin2;
    ASSERT_TRUE(oss.str() == "1010");
}

TEST(BinaryTest, EqualityOperator) {
    Binary bin1("1010");
    Binary bin2("1010");
    Binary bin3("1001");
    ASSERT_TRUE(bin1 == bin2);
    ASSERT_TRUE(!(bin1 == bin3));
}

TEST(BinaryTest, InequalityOperator) {
    Binary bin1("1010");
    Binary bin2("1010");
    Binary bin3("1001");
    ASSERT_TRUE(!(bin1 != bin2));
    ASSERT_TRUE(bin1 != bin3);
}

TEST(BinaryTest, LessThanOperator) {
    Binary bin1("1010");
    Binary bin2("1011");
    Binary bin3("1001");
    ASSERT_TRUE(bin3 < bin1);
    ASSERT_TRUE(bin1 < bin2);
    ASSERT_TRUE(!(bin2 < bin1));
}

TEST(BinaryTest, GreaterThanOperator) {
    Binary bin1("1010");
    Binary bin2("1011");
    Binary bin3("1001");
    ASSERT_TRUE(bin1 > bin3);
    ASSERT_TRUE(bin2 > bin1);
    ASSERT_TRUE(!(bin1 > bin2));
}

TEST(BinaryTest, LessThanOrEqualOperator) {
    Binary bin1("1010");
    Binary bin2("1010");
    Binary bin3("1011");
    ASSERT_TRUE(bin1 <= bin2);
    ASSERT_TRUE(bin1 <= bin3);
    ASSERT_TRUE(!(bin3 <= bin1));
}

TEST(BinaryTest, GreaterThanOrEqualOperator) {
    Binary bin1("1010");
    Binary bin2("1010");
    Binary bin3("1001");
    ASSERT_TRUE(bin1 >= bin2);
    ASSERT_TRUE(bin1 >= bin3);
    ASSERT_TRUE(!(bin3 >= bin1));
}

TEST(BinaryTest, AdditionOperator) {
    Binary bin1("1010");
    Binary bin2("0110");
    Binary result = bin1 + bin2;
    ASSERT_TRUE(result.getSize() == 5);
    std::ostringstream oss;
    oss << result;
    ASSERT_TRUE(oss.str() == "10000");
}

TEST(BinaryTest, SubtractionOperator) {
    Binary bin1("1010");
    Binary bin2("0110");
    Binary result = bin1 - bin2;
    ASSERT_TRUE(result.getSize() == 3);
    std::ostringstream oss;
    oss << result;
    ASSERT_TRUE(oss.str() == "100");
}

TEST(BinaryTest, AdditionAssignmentOperator) {
    Binary bin1("1010");
    Binary bin2("0110");
    bin1 += bin2;
    ASSERT_TRUE(bin1.getSize() == 5);
    std::ostringstream oss;
    oss << bin1;
    ASSERT_TRUE(oss.str() == "10000");
}

TEST(BinaryTest, SubtractionAssignmentOperator) {
    Binary bin1("1010");
    Binary bin2("0110");
    bin1 -= bin2;
    ASSERT_TRUE(bin1.getSize() == 3);
    std::ostringstream oss;
    oss << bin1;
    ASSERT_TRUE(oss.str() == "100");
}

TEST(BinaryTest, OutputOperator) {
    Binary bin("1010");
    std::ostringstream oss;
    oss << bin;
    ASSERT_TRUE(oss.str() == "1010");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}