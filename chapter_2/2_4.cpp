// const限定符
#include <iostream>

extern const int bufSize;

constexpr int size() { // constexpr函数
    return 666;
}

int main(void) {

    // 初始化和const以及extern对于const对象的修饰
    std::cout << "bufSize = " << bufSize << std::endl;

    // const的引用
    const int &rconst = bufSize;
    std::cout << bufSize << ' ' << rconst << std::endl;

    // constexpr: 一定是常量，必须要用常量表达式初始化
    constexpr int limit = 20;

    constexpr int sz = size();

    return 0;  
}