template<typename T>
void f(T&& v) {}

int main()
{
    int a = 1;
    const int b = 2;
    int& c = a;
    f(a);
    f(b);
    f(c);
    f(3);
}