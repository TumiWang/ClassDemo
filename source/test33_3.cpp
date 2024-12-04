#include <type_traits>

template<class NUM_TYPE,
         class DEN_TYPE,
         typename std::enable_if<std::is_integral<NUM_TYPE>{} &&
             std::is_integral<DEN_TYPE>{}, bool>::type = true>
class Rational
{
public:
    Rational(NUM_TYPE numerator, DEN_TYPE denominator): num(numerator), den(denominator) {}

    NUM_TYPE num;
    DEN_TYPE den;
};

int main()
{
    Rational r(1, 2L);
}