#include <iostream>

int a = 42;

decltype(auto) get_a_1() { return a; }

decltype(auto) get_a_2() { return (a); }

int main()
{
    std::cout << get_a_1() << std::endl;
    std::cout << get_a_2() << std::endl;
    // get_a_1() = 15;
    get_a_2() = 15;
    std::cout << get_a_2() << std::endl;
    std::cout << get_a_2() << std::endl;
}