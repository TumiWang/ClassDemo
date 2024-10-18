#include <iostream>

class T
{
public:
    void Test(const int lineno) {
        std::cout << "line:" << lineno << " Call Test without const" << std::endl;
    }
    void Test(const int lineno) const {
        std::cout << "line:" << lineno << " Call Test with const" << std::endl;
    }
};

int main()
{
    const T t;
    t.Test(__LINE__);
    const_cast<T&>(t).Test(__LINE__);
    int i = 15;
    const int& j = i;
    std::cout << "j = " << j << std::endl;
    // j = 10;
    const_cast<int&>(j) = 10;
    std::cout << "j = " << j << std::endl;
}