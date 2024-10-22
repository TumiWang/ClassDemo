#include <cstdint>
#include <iostream>

union U
{
std::int32_t a;
float b;
};

int main()
{
    U u;
    std::int32_t* pa = reinterpret_cast<std::int32_t*>(&u);
    float* pb = reinterpret_cast<float*>(pa);
    *pa = 0x3f400000;
    std::cout << *pb << std::endl;
}