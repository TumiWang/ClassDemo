#include <iostream>
#include <string>

// 等效于 typedef int MyInt;
using MyInt = int;

struct MyStructType1
{
    typedef std::string text_type;
};

struct MyStructType2
{
    using text_type = std::wstring;
};

template<typename T>
using MyTextType = typename T::text_type;

int main()
{
    const auto& stringType = typeid(std::string);
    const auto& wstringType = typeid(std::wstring);
    MyTextType<MyStructType1> text1;
    MyTextType<MyStructType2> text2;

    if (typeid(decltype(text1)) == stringType) {
        std::cout << "MyTextType<MyStructType1> Type is std::string" << std::endl;
    }
    if (typeid(decltype(text1)) != wstringType) {
        std::cout << "MyTextType<MyStructType1> Type is NOT std::wstring" << std::endl;
    }
    if (typeid(decltype(text2)) == wstringType) {
        std::cout << "MyTextType<MyStructType1> Type is std::string" << std::endl;
    }
    if (typeid(decltype(text2)) != stringType) {
        std::cout << "MyTextType<MyStructType1> Type is NOT std::string" << std::endl;
    }
}