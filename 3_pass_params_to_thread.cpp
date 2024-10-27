#include <iostream>
#include <thread>
#include <chrono>

void foo(int x) {
    while (true) {
        std::cout << "foo: " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void foo2(int &x) { // pass by reference
    while (true) {
        std::cout << "foo: " << x << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    int x = 1;
    std::thread t(foo, x);
    t.join();

    std::thread t2(foo, std::ref(x)); // pass by reference
    t2.join();
    return 0;
}