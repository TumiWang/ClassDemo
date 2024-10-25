#include <iostream>

// template<typename... Targs>
// void print(const char* format, Targs... args);

void print(const char* format) {
    std::cout << format << std::endl;
}

template<typename T, typename... Targs>
void print(const char* format, T t, Targs... args) {
    while (*format != '\0') {
        const char& c = *format;
        if ( *format == '*') {
            std::cout << t;
            print(format + 1, args...);
            return;
        }
        std::cout << *(format++);
    }
    std::cout << std::endl;
}

int main()
{
    print("* Hello*");
    print("* Hello*", '?');
    print("* Hello*", "World", "!");
    print("* Hello*", "World", "?", "Test");
}