#include <iostream>

template<typename T>
T& Min(T&& a, T&& b) {
    if (a < b) return a;
    return b;
}

int main()
{
    // std::cout << Min(2.1F, 1.1) << std::endl;
    std::cout << Min(2.1F, 1.1F) << std::endl;
}