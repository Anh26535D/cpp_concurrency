/*
    Most of the time, we cannot use join() function as soon as we launch a thread, as join() function blocks the calling thread.
    We use thread_guard class to join the thread in the destructor of the thread_guard class.
*/

#include <iostream>
#include <thread>

class thread_guard {
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_) : t(t_) {}
    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

int main() {
    std::thread thread1([] {
        std::cout << "Hello from lambda" << std::endl;
        std::cout << std::this_thread::get_id() << std::endl;
    });
    thread_guard guard1(thread1);

    try {
        throw 20;
    } catch (int e) {
        std::cout << "Exception caught" << std::endl;
    }
    return 0;
}