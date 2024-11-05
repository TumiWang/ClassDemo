#include <iostream>
#include <mutex>
#include <thread>

class A final
{
public:
    A() {
        std::cout << "Thread:" << std::this_thread::get_id()
                  << " Construct A -- " << static_cast<void*>(this)
                  << std::endl;
    }
    ~A() {
        std::cout << "Thread:" << std::this_thread::get_id()
                  << " Destruct A -- " << static_cast<void*>(this)
                  << std::endl;
    }
public:
    void info() {
        std::cout << "A run at thread id -- "<< std::this_thread::get_id() << std::endl;
    }
};

thread_local A a;

int main()
{
    std::cout << "Main thread id -- " << std::this_thread::get_id() << std::endl;
    std::thread([](){
        std::cout << "First Work thread id -- " << std::this_thread::get_id() << std::endl;
        a.info();
    }).join();
    std::thread([](){
        std::cout << "Second Work thread id -- " << std::this_thread::get_id() << std::endl;
    }).join();
    std::thread([](){
        std::cout << "Third Work thread id -- " << std::this_thread::get_id() << std::endl;
        a.info();
    }).join();
    a.info();
    std::cout << "Main Function exit" << std::endl;
}