#include <cstdint>
#include <iostream>

#define PRINT_BUFFER(info, buffer)   \
for(std::size_t index = 0, buffer_size = sizeof(buffer)/sizeof(buffer[0]);  \
    index < buffer_size ; ++index) { \
    if (index == 0) std::cout << info;\
    std::cout << buffer[index]; \
    if (index + 1 != buffer_size) std::cout << " ";  \
    else std::cout << std::endl;    \
}

int main()
{
    int buf1[4]{0};
    int buf2[4];
    int buf3[4]{1};
    int buf4[4]{1, 2};
    PRINT_BUFFER("buf1 : ", buf1);
    PRINT_BUFFER("buf2 : ", buf2);
    PRINT_BUFFER("buf3 : ", buf3);
    PRINT_BUFFER("buf4 : ", buf4);
}