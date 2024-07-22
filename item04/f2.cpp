#include <iostream>

// 使用 extern 声明在其他文件中定义的全局变量
extern int globalVar;

// 使用 extern 声明在其他文件中定义的函数
extern void printGlobalVar();

int main() {
    std::cout << "GlobalVar in file2.cpp: " << globalVar << std::endl;
    printGlobalVar(); // 调用在 file1.cpp 中定义的函数
    return 0;
}
