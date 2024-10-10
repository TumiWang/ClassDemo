#include <cassert>
#include <ctime>
#include <string.h>

int main()
{
    std::tm tm1, tm2;
    memset(&tm1, 0, sizeof(tm1));
    memset(&tm2, 0, sizeof(tm2));
    tm1.tm_year = 2024 - 1900; // 2024年
    tm1.tm_mon = 10 - 1; // 10月
    tm1.tm_mday = 1; // 1日
    tm1.tm_hour = 19; // 19点
    std::time_t t = std::mktime(&tm1);
    memcpy(&tm2, std::gmtime(&t), sizeof(tm2));
    tm2.tm_hour = 19;
    assert(tm1.tm_year == tm2.tm_year);
    assert(tm1.tm_mon == tm2.tm_mon);
    assert(tm1.tm_mday == tm2.tm_mday);
    assert(tm1.tm_hour == tm2.tm_hour);
    assert(tm1.tm_sec == tm2.tm_sec);
    assert(tm1.tm_isdst == tm2.tm_isdst);
    assert(tm1.tm_wday == tm2.tm_wday);
    assert(tm1.tm_yday == tm2.tm_yday);
    // 上面的8个断言说明 公开的数据都是一致的
    // 下面的断言说明 内存比较为不一致
    // 这有两种可能
    // 1. 这个结构体内部因为对齐问题有填充
    //    但上面都把内存初始化为0了，这种对齐引入的额外内存，这种情况后续不应该修改的。
    // 2. 有未公开的属性
    //    第一种的可能性降低了，就无形提高了这个的可能性
    assert(memcmp(&tm1, &tm2, sizeof(tm1)) != 0);
}