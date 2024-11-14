#include <gtest/gtest.h>
#include "../include/Stack.h" 
#include "../include/FixedBlockMemoryResource.h" 

struct Person {
    std::string name;
    int age;
    std::string occupation;

    Person(const std::string& n, int a, const std::string& o) : name(n), age(a), occupation(o) {}

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age && occupation == other.occupation;
    }
};

class IntStackTest : public ::testing::Test {
protected:
    FixedBlockMemoryResource customResource{1024}; 
    std::pmr::polymorphic_allocator<int> allocator{&customResource};

    Stack<int, std::pmr::polymorphic_allocator<int>> intStack{10, allocator};

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(IntStackTest, PushAndTop) {
    intStack.push(42);
    ASSERT_EQ(intStack.top(), 42);
}

TEST_F(IntStackTest, PopAndIsEmpty) {
    intStack.push(10);
    intStack.pop();
    ASSERT_TRUE(intStack.isEmpty());
}

TEST_F(IntStackTest, MultiplePushAndCheckOrder) {
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    ASSERT_EQ(intStack.top(), 30);
}

TEST_F(IntStackTest, PopMultipleAndCheckOrder) {
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.pop();
    ASSERT_EQ(intStack.top(), 20);
}

TEST_F(IntStackTest, StackResizesCorrectly) {
    for (int i = 0; i < 10; ++i) {
        intStack.push(i);
    }
    ASSERT_EQ(intStack.top(), 9);
}

TEST_F(IntStackTest, StackClearsCorrectly) {
    for (int i = 0; i < 5; ++i) {
        intStack.push(i);
    }
    while (!intStack.isEmpty()) {
        intStack.pop();
    }
    ASSERT_TRUE(intStack.isEmpty());
}

class PersonStackTest : public ::testing::Test {
protected:
    FixedBlockMemoryResource customResource{4096}; 
    std::pmr::polymorphic_allocator<Person> allocator{&customResource};

    Stack<Person, std::pmr::polymorphic_allocator<Person>> personStack{5, allocator};

    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(PersonStackTest, PushAndTopWithPerson) {
    Person p1{"Alice", 30, "Engineer"};
    personStack.push(p1);
    ASSERT_EQ(personStack.top(), p1);
}

TEST_F(PersonStackTest, PushMultiplePersonsAndCheckOrder) {
    Person p1{"Alice", 30, "Engineer"};
    Person p2{"Bob", 25, "Designer"};
    Person p3{"Charlie", 28, "Doctor"};
    personStack.push(p1);
    personStack.push(p2);
    personStack.push(p3);
    ASSERT_EQ(personStack.top(), p3);
}

TEST_F(PersonStackTest, PopPersonAndCheckTop) {
    Person p1{"Alice", 30, "Engineer"};
    Person p2{"Bob", 25, "Designer"};
    personStack.push(p1);
    personStack.push(p2);
    personStack.pop();
    ASSERT_EQ(personStack.top(), p1);
}

TEST_F(PersonStackTest, StackIsEmptyAfterPopAllPersons) {
    Person p1{"Alice", 30, "Engineer"};
    Person p2{"Bob", 25, "Designer"};
    personStack.push(p1);
    personStack.push(p2);
    personStack.pop();
    personStack.pop();
    ASSERT_TRUE(personStack.isEmpty());
}

TEST_F(PersonStackTest, ReallocateAndCheckIntegrity) {
    for (int i = 0; i < 10; ++i) {
        personStack.push(Person("Name" + std::to_string(i), 20 + i, "Job" + std::to_string(i)));
    }
    ASSERT_EQ(personStack.top(), Person("Name9", 29, "Job9"));
}

TEST_F(PersonStackTest, IterateOverElements) {
    Person p1{"Alice", 30, "Engineer"};
    Person p2{"Bob", 25, "Designer"};
    personStack.push(p1);
    personStack.push(p2);
    auto it = personStack.begin();
    ASSERT_EQ(*it, p1);
    ++it;
    ASSERT_EQ(*it, p2);
}


TEST_F(PersonStackTest, StackReallocationWithPushAndPop) {
    for (int i = 0; i < 20; ++i) {
        personStack.push(Person("Name" + std::to_string(i), 20 + i, "Job" + std::to_string(i)));
    }
    ASSERT_EQ(personStack.top(), Person("Name19", 39, "Job19"));
    for (int i = 0; i < 10; ++i) {
        personStack.pop();
    }
    ASSERT_EQ(personStack.top(), Person("Name9", 29, "Job9"));
}


TEST_F(PersonStackTest, StackHoldsIntegrityWithMemoryAllocator) {
    Person p1{"Eve", 40, "Scientist"};
    personStack.push(p1);
    ASSERT_EQ(personStack.top(), p1);
    personStack.pop();
    ASSERT_TRUE(personStack.isEmpty());
}
