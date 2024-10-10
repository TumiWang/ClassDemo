#include <cassert>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string.h>

int main()
{
    std::tm tm;
    std::tm* p;
    memset(&tm, 0, sizeof(tm));
    tm.tm_year = 2024 - 1900; // 2024年
    tm.tm_mon = 1 - 1; // 1月
    tm.tm_mday = 1; // 1日
    tm.tm_hour = 19; // 19点
    std::time_t t = std::mktime(&tm);
    p = std::localtime(&t);
    char buff[64];
    memset(buff, 0, sizeof(buff));
    std::strftime(buff, sizeof(buff), "%Y %y %m %U %j %d %w", p);
    assert(strcmp(buff, "2024 24 01 00 001 01 1") == 0);
    memset(buff, 0, sizeof(buff));
    std::strftime(buff, sizeof(buff), "%H-%I:%M%S", p);
    assert(strcmp(buff, "19-07:0000") == 0);
    std::cout << std::put_time(p, "%B") << std::endl; // 可能的输出 January
    std::cout << std::put_time(p, "%b") << std::endl; // 可能的输出 Jan
    std::cout << std::put_time(p, "%A") << std::endl; // 可能的输出 Monday
    std::cout << std::put_time(p, "%a") << std::endl; // 可能的输出 Mon
    std::cout << std::put_time(p, "%p") << std::endl; // 可能的输出 PM
    std::cout << std::put_time(p, "%Z") << std::endl; // 可能的输出 CST
    std::cout << std::put_time(std::gmtime(&t), "%c %Z") << std::endl;  // 可能的输出 Mon Jan  1 11:00:00 2024 UTC
}