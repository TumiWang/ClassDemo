#include <iostream>

constexpr int factorial(int n) {
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

int main()
{
    constexpr int a = factorial(6);
    std::cout << a << std::endl;
}