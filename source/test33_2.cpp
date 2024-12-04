#include <type_traits>

template<class T,
    typename std::enable_if<std::is_integral<T>{}, bool>::type = true>
class Rational
{
public:
    Rational(T numerator, T denominator): num(numerator), den(denominator) {}

    T num;
    T den;
};

int main()
{
    Rational r(1, 2);
}