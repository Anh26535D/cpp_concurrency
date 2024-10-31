#include <iostream>
#include <thread>

void foo() {
    std::cout << "foo" << std::endl;
}

void bar() {
    std::cout << "bar" << std::endl;
}

int main() {
    std::thread thread_1(foo);
    std::thread thread_2 = std::move(thread_1);
    thread_1 = std::thread(bar);

    std::thread thread_3(foo);
    thread_1 = std::move(thread_3); // Error because thread_1 is already owning a thread

    thread_1.join();
    thread_2.join();
    thread_3.join();

    return 0;
}