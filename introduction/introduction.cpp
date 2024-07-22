#include <iostream>

class Widget {
private:
    int value;

public:
    // 默认构造函数
    Widget() : value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // 带参数的构造函数
    Widget(int v) : value(v) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // 拷贝构造函数
    Widget(const Widget& other) : value(other.value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // 赋值运算符
    Widget& operator=(const Widget& other) {
        if (this == &other) {
            return *this; // 防止自我赋值
        }
        value = other.value;
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    // 移动构造函数
    Widget(Widget&& other) noexcept : value(other.value) {
        other.value = 0;
        std::cout << "Move constructor called" << std::endl;
    }

    // 移动赋值运算符
    Widget& operator=(Widget&& other) noexcept {
        if (this == &other) {
            return *this; // 防止自我赋值
        }
        value = other.value;
        other.value = 0;
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    } 

    // 析构函数
    ~Widget() {
        std::cout << "Destructor called" << std::endl;
    }

    // 打印 Widget 的值
    void print() const {
        std::cout << "Widget value: " << value << std::endl;
    }
};

int main() {
    // 使用默认构造函数
    Widget w1;
    w1.print();

    // 使用带参数的构造函数
    Widget w2(42);
    w2.print();

    // 使用拷贝构造函数
    std::cout << "w3 = w2 拷贝构造函数" << std::endl;
    Widget w3 = w2;
    w3.print();


    // 使用赋值运算符
    std::cout << "w4 = w2 赋值运算符" << std::endl;
    Widget w4;
    w4 = w2;
    w4.print();

    // 使用移动构造函数
    std::cout << "w5  移动运算符" << std::endl;
    Widget w5 = std::move(w2);
    w5.print();
    w2.print(); // w2 的值应为 0

    // 使用移动赋值运算符
    Widget w6;
    w6 = std::move(w3);
    w6.print();
    w3.print(); // w3 的值应为 0

    return 0;
}
