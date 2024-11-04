#include <chrono>
#include <thread>

int main()
{
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
    }
    // std::this_thread::sleep_for(2s);
    {
        using std::operator""s;
        std::this_thread::sleep_for(2s);
    }
}