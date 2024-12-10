#include <iostream>
#include <string>

int main()
{
    using namespace std::literals::string_literals;
    std::string a = "Hello\0\0World";
    std::string b = "Hello\0\0World"s;
    auto c = "Hello\0\0World"s;
    std::cout << "size of a: " << a.size() << std::endl;
    std::cout << "size of b: " << b.size() << std::endl;
    std::cout << "size of c: " << c.size() << std::endl;
    auto d =  "Hello\0\0World";
    assert(typeid(b) == typeid(c));
    assert(typeid(d) == typeid(const char*));
    assert(typeid(""s) == typeid(std::string));
}