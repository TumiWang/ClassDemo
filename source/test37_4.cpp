#include <cstdint>
#include <iostream>
#include <type_traits>

template<class T, typename std::enable_if<std::is_unsigned<T>::value, bool>::type = true>
constexpr T max_divisor(T n, T m) {
    if (n < m ) {
        T temp = n;
        n = m;
        m = temp;
    }
    while (m != 0) {
        T temp = (n % m);
        n = m;
        m = temp;
    }
    return n;
}

int main()
{
    constexpr auto a = max_divisor<std::uint32_t>(8, 12);
    // constexpr auto b = max_divisor<std::int32_t>(8, 12);
    std::cout << a << std::endl;
}