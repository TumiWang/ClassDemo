#include <type_traits>

int main()
{
    static_assert(std::is_null_pointer<decltype(nullptr)>::value);
    static_assert(not std::is_arithmetic<decltype(nullptr)>::value);
    static_assert(not std::is_null_pointer<decltype(NULL)>::value);
    static_assert(std::is_arithmetic<decltype(NULL)>::value);
}