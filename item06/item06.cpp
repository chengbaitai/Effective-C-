#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    int& refA = x;  // refA 是 x 的引用
    int& refB = y;  // refB 是 y 的引用

    std::cout << "Before assignment:" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl; // 输出 x: 10, y: 20
    std::cout << "refA: " << refA << ", refB: " << refB << std::endl; // 输出 refA: 10, refB: 20

    refA = refB;  // 将 y 的值赋给 x，通过 refA 引用
    // 这相当于 x = y;

    std::cout << "After assignment:" << std::endl;
    std::cout << "x: " << x << ", y: " << y << std::endl; // 输出 x: 20, y: 20
    std::cout << "refA: " << refA << ", refB: " << refB << std::endl; // 输出 refA: 20, refB: 20

    return 0;
}
