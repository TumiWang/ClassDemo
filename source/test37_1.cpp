
int main()
{
    constexpr int a = 1;
    // a = 2;
    const_cast<int&>(a) = 4;
}