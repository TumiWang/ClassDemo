#include <cassert>
#include <ctime>
#include <string.h>

int main()
{
    const int nTimeZone = +8; // 这个可能要根据自己的时区进行修改
    std::tm* p;
    std::tm tm;
    memset(&tm, 0, sizeof(tm));
    tm.tm_year = 2024 - 1900; // 2024年
    tm.tm_mon = 10 - 1; // 10月
    tm.tm_mday = 1; // 1日
    tm.tm_hour = 19; // 19点
    std::time_t t = std::mktime(&tm);
    assert(tm.tm_hour == 19); // 确定std::mktime没有修改tm.tm_hour
    p = std::localtime(&t);
    assert(p->tm_year == tm.tm_year &&
           p->tm_mon == tm.tm_mon &&
           p->tm_mday == tm.tm_mday &&
           p->tm_hour == tm.tm_hour &&
           p->tm_min == tm.tm_min &&
           p->tm_sec == tm.tm_sec); // 确定std::mktime和std::localtime是反操作
    p = std::gmtime(&t);
    assert(p->tm_hour + nTimeZone == tm.tm_hour &&
           p->tm_year == tm.tm_year &&
           p->tm_mon == tm.tm_mon &&
           p->tm_mday == tm.tm_mday &&
           p->tm_min == tm.tm_min &&
           p->tm_sec == tm.tm_sec); // 确定 std::gmtime 时间正好差个时区
}