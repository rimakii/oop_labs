#include "include/FixedBlockMemoryResource.h"
#include "include/Stack.h"
#include <iostream>
#include <memory_resource>

struct Person {
    std::string name;
    int age;
    std::string occupation;

    Person(const std::string& n, int a, const std::string& o) : name(n), age(a), occupation(o) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Person{name: " << p.name << ", age: " << p.age << ", occupation: " << p.occupation << "}";
        return os;
    }
};

int main() {
    FixedBlockMemoryResource customResource(4096); 
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    std::cout << "Testing Stack with int:\n";
    Stack<int, std::pmr::polymorphic_allocator<int>> intStack(5, allocator);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Contents of intStack: ";
    for (auto it = intStack.begin(); it != intStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    intStack.pop();
    std::cout << "Top after pop: " << intStack.top() << "\n\n";


    std::cout << "Testing Stack with Person:\n";
    Stack<Person, std::pmr::polymorphic_allocator<Person>> personStack(2, allocator); 

    personStack.push(Person("Alice", 30, "Engineer"));
    personStack.push(Person("Bob", 25, "Designer"));
    personStack.push(Person("Charlie", 28, "Doctor"));

    std::cout << "Contents of personStack: \n";
    for (auto it = personStack.begin(); it != personStack.end(); ++it) {
        std::cout << *it << "\n";
    }

    personStack.pop();
    std::cout << "\nTop after pop: " << personStack.top() << "\n";

    Stack<int, std::pmr::polymorphic_allocator<int>>* stack1 = 
        new Stack<int, std::pmr::polymorphic_allocator<int>>(10, allocator);
    Stack<Person, std::pmr::polymorphic_allocator<Person>>* stack2 = 
        new Stack<Person, std::pmr::polymorphic_allocator<Person>>(10, allocator);

    delete stack2;

    for (int k = 0; k < 5; ++k) {
        std::cout << "Creating and using stack instance " << k << "\n";
        Stack<int, std::pmr::polymorphic_allocator<int>> tempStack(10, allocator);
        for (int i = 0; i < 5; ++i) {
            tempStack.push(i);
        }
        std::cout << "Top element of temp stack: " << tempStack.top() << "\n";
    }

    delete stack1;

    return 0;
}
