#include <iostream>
#include <thread>

void foo() {
    std::cout << "foo" << std::endl;
    std::cout << "id=" << std::this_thread::get_id() << std::endl; // get the id of the current thread
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // sleep for 1 second
    std::this_thread::yield(); // hint to the implementation to reschedule the execution of threads, allowing other threads to run
}

int main() {
    std::cout << std::thread::hardware_concurrency() << std::endl; // get the number of concurrent threads supported by the implementation

    std::thread thread_1(foo);
    std::thread thread_2(foo);

    thread_1.join();
    thread_2.join();
    return 0;
}