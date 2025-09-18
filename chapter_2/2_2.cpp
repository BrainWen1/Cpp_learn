// 2.2 变量
#include <iostream>

int reused = 42; // 全局变量

int main(void) {

    // 列表初始化
    int a = 0;
    int b = {0};
    int c(0);
    int d{0};
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;

    long double ld = 3.1415926536;
    // int e{ld}, f{ld}; // 使用列表初始化并且存在丢失信息的风险时，编译器会报警告
    int g(ld), h = ld;

    std::cout  << g << ' ' << h << std::endl; // 3 3

    // 作用域
    std::cout << "reused = " << reused << std::endl; // 42
    int reused = 11; // 局部变量
    std::cout << "reused = " << reused << std::endl; // 11
    std::cout << "reused = " << ::reused << std::endl; // 42

    return 0;
}