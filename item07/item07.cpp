#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor called" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor called" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor called" << std::endl; }
    ~Derived() { std::cout << "Derived destructor called" << std::endl; }
};

int main() {
    Base* ptr = new Derived();  // 创建一个 Derived 对象，但通过 Base 指针指向
    delete ptr;  // 通过 Base 指针删除对象
    return 0;
}
