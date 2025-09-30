// 逗号运算符
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int a = 1, b = 15, c = 60;
    cout << (++a, c += b, ++c) << endl;

    // 4.10
    // 4.33
    int x = 0, y = 100;
    cout << (true ? ++x, ++y : --x, --y) << endl;
    cout << x << ' ' << y << endl;
    x = 0, y = 100;
    cout << (false ? ++x, ++y : --x, --y) << endl;
    cout << x << ' ' << y << endl;

    return 0;
}