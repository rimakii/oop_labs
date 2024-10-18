#include <gtest/gtest.h>
#include <iostream>
#include "../include/Array.h"
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include <sstream>

TEST(ArrayTest, AddAndRemoveFigures1) {
    Array array;
    Rectangle* rect = new Rectangle(0, 0, 2, 2);
    Rhombus* rhombus = new Rhombus(0, 0, 1, 1, 2, 0, 1, -1);
    Trapezoid* trapezoid = new Trapezoid(0, 0, 4, 0, 3, 2, 1, 2);
    array.add(rect);
    array.add(rhombus);
    array.add(trapezoid);
    EXPECT_EQ(array.totalArea(), rect->operator double() + rhombus->operator double() + trapezoid->operator double());

    delete rect;
    delete rhombus;
    delete trapezoid;
}
TEST(ArrayTest, AddAndRemoveFigures2) {
    Array array;
    Rectangle* rect = new Rectangle(0, 0, 2, 2);
    Rhombus* rhombus = new Rhombus(0, 0, 1, 1, 2, 0, 1, -1);
    Trapezoid* trapezoid = new Trapezoid(0, 0, 4, 0, 3, 2, 1, 2);
    array.add(rect);
    array.add(rhombus);
    array.add(trapezoid);
    array.remove(1); 

    EXPECT_EQ(array.totalArea(), rect->operator double() + trapezoid->operator double());

    delete rect;
    delete rhombus;
    delete trapezoid;
}

TEST(ArrayTest, EmptyArray) {
    Array array;

    EXPECT_EQ(array.totalArea(), 0.0);
}

TEST(RectangleTest, ConstructorAndArea) {
    Rectangle rect(0, 0, 2, 2);

    double area = rect.operator double();

    EXPECT_EQ(area, 4.0);
}

TEST(RectangleTest, Center) {
    Rectangle rect(0, 0, 2, 2);

    std::pair<double, double> center = rect.center();

    EXPECT_EQ(center, std::make_pair(1.0, 1.0));
}

TEST(RectangleTest, Print) {
    Rectangle rect(0, 0, 2, 2);

    std::ostringstream output;
    rect.print(output);

    std::string expectedOutput = "Rectangle: (0, 0) to (2, 2)";

    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(RectangleTest, Read1) {
    Rectangle rect;

    std::istringstream input("0 0 2 2");
    rect.read(input);

    EXPECT_EQ(rect.center(), std::make_pair(1.0, 1.0));
}
TEST(RectangleTest, Read2) {
    Rectangle rect;

    std::istringstream input("0 0 2 2");
    rect.read(input);

    EXPECT_EQ(rect.operator double(), 4.0);
}

TEST(RhombusTest, ConstructorAndArea) {
    Rhombus rhombus(0, 0, 1, 1, 2, 0, 1, -1);

    double area = rhombus.operator double();

    EXPECT_EQ(area, 2.0);
}

TEST(RhombusTest, Center) {
    Rhombus rhombus(0, 0, 1, 1, 2, 0, 1, -1);

    std::pair<double, double> center = rhombus.center();

    EXPECT_EQ(center, std::make_pair(1.0, 0.0));
}

TEST(RhombusTest, Print) {
    Rhombus rhombus(0, 0, 1, 1, 2, 0, 1, -1);

    std::ostringstream output;
    rhombus.print(output);

    std::string expectedOutput = "Rhombus: (0, 0), (1, 1), (2, 0), (1, -1)";

    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(RhombusTest, Read1) {
    Rhombus rhombus;

    std::istringstream input("0 0 1 1 2 0 1 -1");
    rhombus.read(input);

    EXPECT_EQ(rhombus.operator double(), 2.0);
}

TEST(RhombusTest, Read2) {
    Rhombus rhombus;

    std::istringstream input("0 0 1 1 2 0 1 -1");
    rhombus.read(input);

    EXPECT_EQ(rhombus.center(), std::make_pair(1.0, 0.0));
}

TEST(TrapezoidTest, ConstructorAndArea) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 2, 1, 2);

    double area = trapezoid.operator double();

    EXPECT_EQ(area, 6.0);
}

TEST(TrapezoidTest, Center) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 2, 1, 2);

    std::pair<double, double> center = trapezoid.center();

    EXPECT_EQ(center, std::make_pair(2.0, 1.0));
}

TEST(TrapezoidTest, Print) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 2, 1, 2);

    std::ostringstream output;
    trapezoid.print(output);

    std::string expectedOutput = "Trapezoid: (0, 0), (4, 0), (3, 2), (1, 2)";

    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(TrapezoidTest, Read1) {
    Trapezoid trapezoid;

    std::istringstream input("0 0 4 0 3 2 1 2");
    trapezoid.read(input);

    EXPECT_EQ(trapezoid.center(), std::make_pair(2.0, 1.0));
}

TEST(TrapezoidTest, Read2) {
    Trapezoid trapezoid;

    std::istringstream input("0 0 4 0 3 2 1 2");
    trapezoid.read(input);

    EXPECT_EQ(trapezoid.operator double(), 6.0);
}