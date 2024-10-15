#include <cstdint>
#include <iostream>

template<typename T>
void PrintMemory(T& v)
{
    const auto size = sizeof(v);
    // std::cout << typeid(T).name() << " of the Value(" << v;
    // std::cout << ") use memory:";
    std::cout << std::hex;
    const char* p =(const char*)(&v);
    for(int i = 0; i < size; ++i) {
        std::cout << (unsigned char)(*(p + i));
    }
    std::cout << std::dec;
}

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
    PrintMemory(a2);
}