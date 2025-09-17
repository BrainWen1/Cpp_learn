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
    std::cout << "a really really long string literal "
                 "that spans two lines" << std::endl;
    // bool bol = true;
    // int *p = nullptr;
    
    // 转义序列
    std::cout << '\n';
    std::cout << "\tHi!\n" << std::endl;

    std::cout << "Hi \x4do\115!\n";
    std::cout << '\115' << '\n';

    // 指定字面值的类型
    //           wchar_t        utf-8编码    unsigned long long   float           long double
    std::cout << L'a' << ' ' << u8"hi!" << ' ' << 42ULL << ' ' << 1E-3F << ' ' << 3.14159L << std::endl;

    // 2.1.3
    // 2.8
    std::cout << "2M\n";
    std::cout << "2\tM\n";

    return 0;
}