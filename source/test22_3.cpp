#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 4};
    for (auto v: v) {
        // char v = 'G';
        std::cout << v << std::endl;
    }
}