#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

void show(char v)
{
    std::cout << "char: " << (int32_t)v << std::endl;
}

void show(int16_t v)
{
    std::cout << "int16_t: " << (int32_t)v << std::endl;
}

int main()
{
    std::array<int32_t, 5> arr{{1, 2, 3, 4, 5}};
    // std::for_each(arr.begin(), arr.end(), show);
    std::for_each(arr.begin(), arr.end(), static_cast<void(*)(int16_t)>(show));
}