#include <iostream>
#include <memory>
#include "include/Array.h"
#include "include/Rectangle.h"
#include "include/Trapezoid.h"
#include "include/Rhombus.h"

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    while (true) {
        std::cout << "1. Add Rectangle\n"
                  << "2. Add Trapezoid\n"
                  << "3. Add Rhombus\n"
                  << "4. Remove Figure by Index\n"
                  << "5. Print All Figures\n"
                  << "6. Total Area\n"
                  << "7. Exit\n"
                  << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            int x1, y1, x2, y2;
            std::cout << "Enter coordinates (x1 y1 x2 y2): ";
            std::cin >> x1 >> y1 >> x2 >> y2;
            figures.add(std::make_shared<Rectangle<int>>(x1, y1, x2, y2));
        } else if (choice == 2) {
            int x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            figures.add(std::make_shared<Trapezoid<int>>(x1, y1, x2, y2, x3, y3, x4, y4));
        } else if (choice == 3) {
            int x1, y1, x2, y2, x3, y3, x4, y4;
            std::cout << "Enter coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            figures.add(std::make_shared<Rhombus<int>>(x1, y1, x2, y2, x3, y3, x4, y4));
        } else if (choice == 4) {
            size_t index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;
            figures.remove(index);
        } else if (choice == 5) {
            figures.printAll();
        } else if (choice == 6) {
            std::cout << "Total Area: " << figures.totalArea() << std::endl;
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}