#include <iostream>

auto factorial(int64_t n)
{
    if (n <= 1) {
        return (int64_t)1;
    }
    return n * factorial(n - 1);
}

// auto factorial(int64_t n)
// {
//     if (n > 1) {
//         return n * factorial(n - 1);;
//     }
//     return (int64_t)1;
// }

int main()
{
    std::cout << "5! = " << factorial(5) << std::endl;
}