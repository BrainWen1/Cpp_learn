// 类型转换
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 显式转换
    int i = 4, j = 3;
    double d = static_cast<double> (i) / j;
    cout << d << endl;

    return 0;
}