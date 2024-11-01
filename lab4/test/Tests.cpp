#include <gtest/gtest.h>
#include <memory>
#include "../include/Rectangle.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Array.h"

TEST(PointTest, Initialization) {
    Point<int> p1(1, 2);

    EXPECT_EQ(p1.x, 1);
    EXPECT_EQ(p1.y, 2);
}

TEST(RectangleTest, InitializationAndArea1) {
    Rectangle<int> rect1(0, 0, 4, 2);

    Point<int> center1 = rect1.center();
    double area1 = rect1.area();

    EXPECT_EQ(center1.x, 2);
    EXPECT_EQ(center1.y, 1);
    EXPECT_EQ(area1, 8);
}

TEST(RectangleTest, InitializationAndArea2) {
    Rectangle<int> rect2(1, 1, 5, 3);

    Point<int> center2 = rect2.center();
    double area2 = rect2.area();

    EXPECT_EQ(center2.x, 3);
    EXPECT_EQ(center2.y, 2);
    EXPECT_EQ(area2, 8);
}

TEST(TrapezoidTest, InitializationAndArea1) {
    Trapezoid<int> trapezoid1(0, 0, 4, 0, 2, 2, 2, 2);

    Point<int> center1 = trapezoid1.center();
    double area1 = trapezoid1.area();

    EXPECT_EQ(center1.x, 2);
    EXPECT_EQ(center1.y, 1);
    EXPECT_EQ(area1, 4);
}

TEST(TrapezoidTest, InitializationAndArea2) {
    Trapezoid<int> trapezoid2(1, 1, 5, 1, 3, 3, 3, 3);

    Point<int> center2 = trapezoid2.center();
    double area2 = trapezoid2.area();

    EXPECT_EQ(center2.x, 3);
    EXPECT_EQ(center2.y, 2);
    EXPECT_EQ(area2, 4);
}

TEST(RhombusTest, InitializationAndArea1) {
    Rhombus<int> rhombus1(0, 0, 2, 2, 4, 0, 2, -2);

    Point<int> center1 = rhombus1.center();
    double area1 = rhombus1.area();

    EXPECT_EQ(center1.x, 2);
    EXPECT_EQ(center1.y, 0);
    EXPECT_EQ(area1, 8);
}

TEST(RhombusTest, InitializationAndArea2) {
    Rhombus<int> rhombus2(1, 1, 3, 3, 5, 1, 3, -1);

    Point<int> center2 = rhombus2.center();
    double area2 = rhombus2.area();

    EXPECT_EQ(center2.x, 3);
    EXPECT_EQ(center2.y, 1);
    EXPECT_EQ(area2, 8);
}
TEST(ArrayTest, Initialization) {
    Array<std::shared_ptr<Figure<int>>> figures;

    EXPECT_EQ(figures.get_size(), 0);
}

TEST(ArrayTest, PushBack) {
    Array<std::shared_ptr<Figure<int>>> figures;

    figures.push_back(std::make_shared<Rectangle<int>>(0, 0, 4, 2));
    figures.push_back(std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 2, 2, 2, 2));
    figures.push_back(std::make_shared<Rhombus<int>>(0, 0, 2, 2, 4, 0, 2, -2));

    EXPECT_EQ(figures.get_size(), 3);
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<int>>> figures;

    figures.push_back(std::make_shared<Rectangle<int>>(0, 0, 4, 2));
    figures.push_back(std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 2, 2, 2, 2));
    figures.push_back(std::make_shared<Rhombus<int>>(0, 0, 2, 2, 4, 0, 2, -2));

    double total_area = figures.total_area();

    EXPECT_EQ(total_area, 20);
}

TEST(ArrayTest, Remove) {
    Array<std::shared_ptr<Figure<int>>> figures;

    figures.push_back(std::make_shared<Rectangle<int>>(0, 0, 4, 2));
    figures.push_back(std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 2, 2, 2, 2));
    figures.push_back(std::make_shared<Rhombus<int>>(0, 0, 2, 2, 4, 0, 2, -2));

    figures.remove(1);

    EXPECT_EQ(figures.get_size(), 2);

    double total_area = figures.total_area();

    EXPECT_EQ(total_area, 16);
}

TEST(ArrayTest, RemoveNonExistentIndex) {
    Array<std::shared_ptr<Figure<int>>> figures;

    figures.push_back(std::make_shared<Rectangle<int>>(0, 0, 4, 2));
    figures.push_back(std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 2, 2, 2, 2));

    EXPECT_THROW(figures.remove(2), std::out_of_range);
}

TEST(ArrayTest, ResizeAndMove) {
    Array<std::shared_ptr<Figure<int>>> figures;

    for (int i = 0; i < 15; ++i) {
        figures.push_back(std::make_shared<Rectangle<int>>(0, 0, 4, 2));
    }

    EXPECT_EQ(figures.get_size(), 15);

    double total_area = figures.total_area();

    EXPECT_EQ(total_area, 120);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}