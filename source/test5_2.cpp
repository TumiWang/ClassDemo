#include <iostream>
#include <vector>
#include <string>

class MyObject
{
public:
    MyObject() = default;
    MyObject(int index): index_(index) {}

    ~MyObject() {}

    int GetValue() const {
        return index_;
    }

    void SetValue(int index) {
        index_ = index;
    }

private:
    int index_ = 10;
};

int main()
{
    std::vector<MyObject> items(2);

    // 打印 items 的内容
    auto printItemsInfo = [&items]() {
        std::string text;
        for (const auto& item: items) {
            if (text.empty()) {
                text = std::to_string(item.GetValue());
            } else {
                text += ", " + std::to_string(item.GetValue());
            }
        }
        std::cout << "items = [" << text << "]" << std::endl;
    };

    printItemsInfo();

    for (size_t i = 0; i < items.size(); ++i) {
        items[i].SetValue(i + 1);
    }
    items.emplace_back(3);

    printItemsInfo();
}