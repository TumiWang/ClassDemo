#include <cstdint>
#include <iostream>

int main()
{
    std::cout << "size of int16_t: " << sizeof(std::int16_t) << std::endl;
    std::cout << "size of int_fast16_t: " << sizeof(std::int_fast16_t) << std::endl;
    std::cout << "size of int_least16_t: " << sizeof(std::int_least16_t) << std::endl;
    std::cout << "Max of int16_t:" << INT16_MAX << std::endl;
    std::int16_t a1 = 33000;
    std::int_fast16_t a2 = 33000;
    std::int_least16_t a3 = 33000;
    std::cout << "a1=" << a1 << " a2=" << a2 << " a3=" << a3 << std::endl;
}