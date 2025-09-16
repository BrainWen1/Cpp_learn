#include <iostream>

int main(void) {

    // 算术类型
    std::cout << "bool: " << sizeof(bool) << std::endl; // 1
    std::cout << "char: " << sizeof(char) << std::endl; // 1
    std::cout << "wchar_t: " << sizeof(wchar_t) << std::endl; // 2
    std::cout << "char16_t: " << sizeof(char16_t) << std::endl; // 4
    std::cout << "char32_t: " << sizeof(char32_t) << std::endl; // 4
    std::cout << "short: " << sizeof(short) << std::endl; // 2
    std::cout << "int: " << sizeof(int) << std::endl; // 4
    std::cout << "long: " << sizeof(long) << std::endl; // 4
    std::cout << "long long: " << sizeof(long long) << std::endl; // 8
    std::cout << "float: " << sizeof(float) << std::endl; // 4
    std::cout << "double: " << sizeof(double) << std::endl; // 8
    std::cout << "long double: " << sizeof(long double) << std::endl; // 16

    // 类型转换
    unsigned int u = 10;
    int i = -42;
    std::cout << i + i << ' ' << i + u << std::endl; // -84 4294967264

    unsigned u1 = 42, u2 = 10;
    std::cout << u1 - u2 << ' ' << u2 - u1 << std::endl; // 32 4294967264

    int cnt = 0;
    for(unsigned i = 10; i >= 0; --i) { // 死循环
        // std::cout << i << ' ';

        if(cnt++ == 100) {
            std::cout << std::endl;
            break;
        }
    }

    int i1 = 10, i2 = 42;
    std::cout << i2 - i1 << ' ' << i1 - i2 << ' ' << i1 - u2 << ' ' << u2 - i1 << std::endl;

    // 字面值常量

    return 0;
}