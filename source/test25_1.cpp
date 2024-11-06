void f(int min, int max);
// void f(int, int); // 也可以写成这样
// void f(int min, int max = min);

void f(int min, int max)
{
    // ...
    // int min = 4;
    // ...
    {
        int min = 4;
    }
    // ...
}

int main()
{
    
}