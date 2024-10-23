#include <array>
#include <iostream>

template<typename T>
using Point3D = std::array<T, 3>;

int main()
{
    Point3D<double> point;
    std::cout << point.size() << std::endl;
}