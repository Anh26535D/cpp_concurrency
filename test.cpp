#include <iostream>

class MyClass {
public:
    int value;

    // Constructor
    MyClass(int v) : value(v) {
        std::cout << "Constructor called with value = " << value << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass &other) : value(other.value) {
        std::cout << "Copy constructor called. Copying value = " << other.value << std::endl;
    }

    // Move Constructor
    MyClass(MyClass &&other) noexcept : value(other.value) {
        std::cout << "Move constructor called. Moving value = " << other.value << std::endl;
        other.value = 0;  // Optional: Clear moved-from value for clarity
    }

    // Destructor
    ~MyClass() {
        std::cout << "Destructor called for value = " << value << std::endl;
    }
};

// Function that returns an object by value
MyClass createObject(int v) {
    MyClass obj(v);  // Normal constructor is called here
    return obj;      // Return by value
}

int main() {
    std::cout << "Calling createObject..." << std::endl;
    MyClass result = createObject(42);  // Copy or move constructor is called here
    std::cout << "Result value in main = " << result.value << std::endl;

    return 0;
}
