#include <iostream>
 
struct A
{
    ~A() { std::cout << "Destruct A" << std::endl; }
    void info() { std::cout << "Call A::Info" << std::endl; }
};


int main()
{
    A a;
    std::cout << "场景一" << std::endl;
    {
        decltype(a) temp(a);
        temp.info();
    }
    std::cout << "场景二" << std::endl;
    {
        decltype((a)) temp(a);
        temp.info();
    }
    std::cout << "完成" << std::endl;
}