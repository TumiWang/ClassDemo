#include <cassert>
#include <ctime>
#include <string.h>

int main()
{
    std::tm tm;
    memset(&tm, 0, sizeof(tm));
    tm.tm_year = 2024 - 1900; // 2024年
    tm.tm_mon = 10 - 1; // 10月
    tm.tm_mday = 1; // 1日
    assert(tm.tm_yday == 0);
    std::time_t t = std::mktime(&tm);
    assert(tm.tm_yday == 274); // 当年的第275天
    assert(tm.tm_wday == 2); // 星期二
}