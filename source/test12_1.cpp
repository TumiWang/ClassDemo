#include <cassert>
#include <chrono>

int main()
{
    // d1 为 30秒
    auto d1 = std::chrono::duration<float, std::ratio<1>>(30);
    assert(d1.count() == 30.0);

    // d2 为 29.5分
    auto d2 = std::chrono::duration<float, std::ratio<60>>(29.5);
    assert(d2.count() == 29.5);

    // 29.5分 加上 30秒 我们先要确定这个结果的单位是什么
    // d3 这个变量不要使用auto 自动推导， 推导的类型(单位是秒？还是分？)可能不符合预期
    std::chrono::duration<float, std::ratio<3600>> d3 = d1 + d2;
    // 这里单位使用的是小时
    // 29.5分 加上 30秒 等于 0.5小时
    assert(d3.count() == 0.5);
}