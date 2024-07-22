#include <iostream>
#include <string>

class Base {
public:
    Base(const std::string &s) : baseStr(s) {
        std::cout << "Base constructor called\n";
    }
    Base(const Base &other) : baseStr(other.baseStr) {
        std::cout << "Base copy constructor called\n";
    }
private:
    std::string baseStr;
};

class Member {
public:
    Member(int v) : value(v) {
        std::cout << "Member constructor called\n";
    }
    Member(const Member &other) : value(other.value) {
        std::cout << "Member copy constructor called\n";
    }
private:
    int value;
};

class MyClass : public Base {
public:
    MyClass(const std::string &s, int v) : Base(s), member(v) {
        std::cout << "MyClass constructor called\n";
    }
    // 默认的拷贝构造函数
    // MyClass(const MyClass &other) = default;
private:
    Member member;
};

int main() {
    MyClass obj1("Hello", 42);
    MyClass obj2(obj1);  // 调用默认的拷贝构造函数

    return 0;
}
