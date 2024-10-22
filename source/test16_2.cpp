#include <cstdint>
#include <iostream>

int main()
{
    std::int32_t i = 0x1234;
    std::cout << std::hex << "i = "  << i << std::endl;
    reinterpret_cast<std::uint8_t&>(i) = 0x0f;
    std::cout << std::hex << "i = "  << i << std::endl;
    reinterpret_cast<std::uint8_t&>(i) = 0x0134;
    std::cout << std::hex << "i = "  << i << std::endl;
}