// const限定符
#include <iostream>

extern const int bufSize;

int main(void) {

    // 初始化和const以及extern对于const对象的修饰
    std::cout << "bufSize = " << bufSize << std::endl;

    // const的引用
    const int &rconst = bufSize;
    std::cout << bufSize << ' ' << rconst << std::endl;

    return 0;  
}