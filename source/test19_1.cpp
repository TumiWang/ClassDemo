#include <iostream>
#include <memory>

void my_delete(int* p)
{
    std::cout << "Call my_delete function -- "
              << static_cast<void*>(p) << std::endl;
    delete p;
}

int main()
{
    int* p = new int;
    *p = 15;
    std::unique_ptr<int, decltype(&my_delete)> u(p, &my_delete);
    std::cout << "p -> " << static_cast<void*>(p) << std::endl;
}