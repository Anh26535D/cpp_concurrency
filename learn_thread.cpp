#include <iostream>
#include <thread>

void foo() {
    std::cout << "Hello from function" << std::endl;
    std::cout << std::this_thread::get_id() << std::endl;
}

class Bar {
public:
    void operator()() {
        std::cout << "Hello from callable class" << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    }
};

int main() {
    std::thread thread1(foo);
    if (thread1.joinable()) {
        std::cout << "Thread 1 is joinable" << std::endl;
        thread1.join();
    }
    
    
    Bar obj;
    std::thread thread2(obj);
    if (thread2.joinable()) {
        std::cout << "Thread 2 is joinable" << std::endl;
        thread2.join();
    }

    std::thread thread3([] {
        std::cout << "Hello from lambda" << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    });
    if (thread3.joinable()) {
        std::cout << "Thread 3 is joinable" << std::endl;
        thread3.join();
    }
    
    std::cout << std::this_thread::get_id() << std::endl;
    return 0;
}