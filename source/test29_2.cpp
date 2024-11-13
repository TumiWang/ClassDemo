#include <cstddef>
#include <iostream>

void test(long) {
    std::cout << "long type" << std::endl;
}

void test(int) {
    std::cout << "int type" << std::endl;
}

void test(void*) {
    std::cout << "pointer type" << std::endl;
}

int main()
{
    test(nullptr);
    test(NULL);
}