#include <iostream>

template<typename T>
void test(const T& t) {
    std::cout << t << std::endl;
}

int main()
{
    auto test_int = test<int>;
    test_int(9);
    test_int(9.8);
    test(9);
    test(9.8);
}