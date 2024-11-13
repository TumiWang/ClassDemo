#include <type_traits>

struct A {};

int main()
{
    static_assert(std::is_fundamental<int>::value);
    static_assert(std::is_fundamental<int>::value == true);
    static_assert(std::is_fundamental_v<int>);
    static_assert(not std::is_fundamental_v<A>);
    static_assert(std::is_compound_v<A>);
}