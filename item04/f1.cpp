#include <iostream>

// 定义一个全局静态变量
int globalVar = 10;

// 定义一个函数
void printGlobalVar() {
    std::cout << "GlobalVar in file1.cpp: " << globalVar << std::endl;
}
