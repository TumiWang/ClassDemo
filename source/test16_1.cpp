#include <cstdint>
#include <cstdio>

struct A {
    int16_t v_;
};

struct B {
    char v_;
};

int main()
{
    A a;
    std::uintptr_t j = reinterpret_cast<std::uintptr_t>(&a);
    B* b = reinterpret_cast<B*>(&a);
    A* p = reinterpret_cast<A*>(j + 1);
    printf("%p\n", &a);
    printf("%p\n", b);
    printf("%p\n", p);
}