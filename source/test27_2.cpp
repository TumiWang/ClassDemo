int main()
{
    volatile int a = 15;
    // int& b = a;
    int& c = const_cast<int&>(a);
}