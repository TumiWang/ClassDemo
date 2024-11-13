#include <type_traits>
#include <vector>

struct A {};

class B {};

void f() {}

int main()
{
    int a = 1;
    int& b = a;
    int* c = &a;
    auto d = [](){};
    std::vector<int> m;
    int n[] = {0};
    static_assert(std::is_arithmetic<decltype(a)>::value);
    static_assert(std::is_reference<decltype(b)>::value);
    static_assert(std::is_pointer<decltype(c)>::value);
    static_assert(std::is_pointer<decltype(&f)>::value);
    static_assert(not std::is_function<decltype(&f)>::value);
    static_assert(std::is_function<decltype(f)>::value);
    static_assert(std::is_class<A>::value);
    static_assert(std::is_class<B>::value);
    static_assert(not std::is_enum<B>::value);
    static_assert(std::is_class<decltype(d)>::value);
    static_assert(std::is_class<decltype(m)>::value);
    static_assert(std::is_array<decltype(n)>::value);
}