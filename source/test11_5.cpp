#include <cassert>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    const std::string text1 = "2024-Oct-01 19:29:28";
    std::tm tm = { 0 };
    std::istringstream ss1(text1);
    ss1 >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    assert(ss1.fail()); // 断言失败

    std::istringstream ss2(text1);
    ss2 >> std::get_time(&tm, "%Y-%b-%d %H:%M:%S");
    assert(!ss2.fail());
    // 输出结果为系统默认格式，我的环境为 Sun Oct  1 19:29:28 2024
    std::cout << std::put_time(&tm, "%c") << std::endl;
    // 上一行的输出说明已经有了日期数据，但是断言没有设置tm_yday
    assert(tm.tm_yday == 0);
    std::mktime(&tm);
    // 断言现在设置了有效的tm_yday
    assert(tm.tm_yday == 274);

    // 假如这是10点11分13秒的时间描述
    std::istringstream ss3("10-11:12");
    ss3 >> std::get_time(&tm, "%H-%M:%S");
    // 输出结果: 10点11分12秒
    std::cout << std::put_time(&tm, "%H点%M分%S秒") << std::endl;

    // 设置为11月2日8点 没有年等的信息
    std::istringstream ss4("11月2日 8点");
    tm.tm_year = 2000 - 1900; // 设置为2000年
    tm.tm_mon = 10 - 1; // 设置为10月
    ss4 >> std::get_time(&tm, "%m月%d日 %H点");
    // 断言tm_year没有变化 -- 还是2000年
    assert(tm.tm_year == 2000 - 1900);
    // 断言tm_mon变为了11月
    assert(tm.tm_mon == 11 - 1);
}