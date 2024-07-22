#include <iostream>
#include <string>
#include <list>

// 自定义类型
class PhoneNumber {
public:
    PhoneNumber(const std::string& number) : number(number) {}
private:
    std::string number;
};

// ABEntry 类使用初始化列表进行初始化
class ABEntry {
public:
    ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
        : theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0) {
        std::cout << "ABEntry constructor called." << std::endl;
    }

    void display() const {
        std::cout << "Name: " << theName << std::endl;
        std::cout << "Address: " << theAddress << std::endl;
        std::cout << "Number of phones: " << thePhones.size() << std::endl;
        std::cout << "Times consulted: " << numTimesConsulted << std::endl;
    }

private:
    std::string theName;
    std::string theAddress;
    std::list<PhoneNumber> thePhones;
    int numTimesConsulted;
};

class FileSystem {
public:
    std::size_t numDisks() const { return 5; }
};

// 使用局部静态变量的示例
FileSystem& getFileSystem() {
    static FileSystem fs;
    return fs;
}


class Directory {
public:
    Directory() {
        std::size_t disks = getFileSystem().numDisks();
        std::cout << "Directory constructor called. Disks: " << disks << std::endl;
    }
};

int main() {
    // 测试内建类型初始化
    int x = 10; // 手动初始化
    std::cout << "x: " << x << std::endl;

    // 测试自定义类型和初始化列表
    std::list<PhoneNumber> phones = { PhoneNumber("123-456-7890"), PhoneNumber("987-654-3210") };
    ABEntry entry("John Doe", "123 Elm Street", phones);
    entry.display();

    // 测试局部静态变量
    Directory dir; // 触发 FileSystem 的静态对象初始化

    return 0;
}
