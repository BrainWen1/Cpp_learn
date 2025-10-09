// 函数匹配
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void f() {
    cout << 1 << endl;
}

void f(int val) {
    cout << 2 << endl;
}

void f(int val1, int val2) {
    cout << 3 << endl;
}

void f(double d1, double d2 = 3.14) {
    cout << 4 << endl;
}

int main(void) {

    // 6.6
    // 6.51
    // f(2.56, 42); // call of overloaded 'f(double, int)' is ambiguous
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}