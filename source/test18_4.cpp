#include <iomanip>
#include <iostream>

template<class T>
constexpr T pi = T(3.1415926535897932L);

int main()
{
    std::cout << std::setw(10) << std::setprecision(10);
    std::cout << pi<float> << std::endl;
    std::cout << pi<double> << std::endl;
}