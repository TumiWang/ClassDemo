#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>

int main()
{
    auto start1 = std::chrono::steady_clock::now();
    auto start2 = std::clock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    auto end2 = std::clock();
    auto end1 = std::chrono::steady_clock::now();
    auto d2 = 1000.0 * (end2 - start2) / CLOCKS_PER_SEC;
    auto d1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
    std::cout << "" << d2 << "毫秒" << std::endl;
    std::cout << "" << d1.count() << "毫秒" << std::endl;
}