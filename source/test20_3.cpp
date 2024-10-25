#include <iostream>

class myostream final
{
public:
    myostream(const char* format) : format_(format) {
        print(true);
    }
    ~myostream() {
        print(false);
    }
    void print(bool check_key) {
        while (!!format_) {
            const char& c = *format_;
            if (c == '\0') {
                format_ = nullptr;
                std::cout << std::endl;
                break;
            }
            if (check_key && c == key_) break;
            std::cout << c;
            ++format_;
        }
    }
    bool next() {
        if (!!format_) {
            if (*format_ == key_) {
                ++format_;
                return true;
            }
        }
        return false;
    }
private:
    const char* format_;
    const char key_ = '*';
};

template<typename T>
myostream& operator << (T& t, myostream& out)
{
    if (out.next()) {
        std::cout << t;
        out.print(true);
    }
    return out;
}

template<typename... Targs>
void print(const char* format, Targs... args)
{
    myostream out(format);
    (args << ... << out);
}

int main()
{
    print("* Hello*");
    print("* Hello*", '?');
    print("* Hello*", "World", "!");
    print("* Hello*", "World", "?", "Test");
}