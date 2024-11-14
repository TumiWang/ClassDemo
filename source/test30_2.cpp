#include <type_traits>

int main()
{
    int a = 1;
    static_assert(std::is_arithmetic<decltype(a)>::value);
    static_assert(not std::is_arithmetic<decltype((a))>::value);
    static_assert(not std::is_reference<decltype(a)>::value);
    static_assert(std::is_reference<decltype((a))>::value);
}