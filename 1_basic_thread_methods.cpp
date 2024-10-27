#include <iostream>
#include <thread>

void foo() {
    std::cout << "Hello from function" << std::endl;
    // get_id() returns the thread id
    std::cout << std::this_thread::get_id() << std::endl;
}

class Bar {
public:
    void operator()() {
        std::cout << "Hello from callable class" << std::endl;
        // get_id() returns the thread id
        std::cout << std::this_thread::get_id() << std::endl;
    }
};

int main() {
    // We can create a thread by passing a function, a callable object, or a lambda expression
    // A thread is joinable if it is not joined or detached
    // A thread is not joinable if it is joined or detached
    // If we don't join or detach a thread, the program will terminate when the thread goes out of scope
    // We can call detach() function as soon as we launch a thread, as detach call does not block the calling thread
    // In some occasions, we cannot call join function as soon as we launch a thread, as join call block the calling thread
    
    std::thread thread1(foo);
    if (thread1.joinable()) {
        std::cout << "Thread 1 is joinable" << std::endl;
        thread1.join(); // The main thread waits for thread1 to finish
    }
    
    Bar obj;
    std::thread thread2(obj);
    if (thread2.joinable()) {
        std::cout << "Thread 2 is joinable" << std::endl;
        // The main thread doesn't wait for thread2 to finish
        // Thread2 runs independently
        thread2.detach(); 
    }

    std::thread thread3([] {
        std::cout << "Hello from lambda" << std::endl;
        // get_id() returns the thread id
        std::cout << std::this_thread::get_id() << std::endl;
    });
    if (thread3.joinable()) {
        std::cout << "Thread 3 is joinable" << std::endl;
        thread3.join();
    }
    
    std::cout << std::this_thread::get_id() << std::endl;
    return 0;
}