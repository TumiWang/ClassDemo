#include <cstddef>
#include <iostream>

constexpr char default_char = ' ';

class MyConstStr
{
public:
    template<std::size_t N>
    constexpr MyConstStr(const char(&str)[N])
        : str_(str), n_(N - 1) {}
public:
    constexpr char operator[](std::size_t pos) const {
        return pos < n_ ? str_[pos] : default_char;
    }
    constexpr std::size_t size() const { return n_; }
private:
    const char* str_;
    std::size_t n_;
};

constexpr std::size_t CalcUpperCount(MyConstStr str) {
    std::size_t count = 0;
    for (std::size_t index = 0; index < str.size(); ++index) {
        if (str[index] >= 'A' && str[index] <= 'Z')
            ++count;
    }
    return count;
}

int main()
{
    constexpr std::size_t a = CalcUpperCount(MyConstStr("Hello Literal Type"));
    std::cout << a << std::endl;
}