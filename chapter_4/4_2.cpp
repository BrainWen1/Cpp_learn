// 算术运算符
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 小整数类型 -> 较大整数类型
    int a = 1;
    bool b = true;
    int c = a + b;
    cout << a << ' ' << b << ' ' << c << endl;

    // 整数除法 浮点数除法
    cout << 21 / 6 << ' ' << 14.76 / 4.1 << endl;

    // m % n 的符号只取决于 m
    cout << 21 % 6 << ' ' << -21 % 6 << ' ' << 21 % -6 << ' ' << -21 % -6 << endl;

    return 0;
}