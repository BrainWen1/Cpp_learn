// 逻辑和关系运算符
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 短路求值
    int a = 0;
    if(false && ++a) {}
    cout << a << endl;

    if(true || ++a) {}
    cout << a << endl;

    // 布尔字面值
    if(a == true) { // true被转换成int类型，即1
        cout << 'y' << endl;
    } else {
        cout << 'n' << endl;
    }

    return 0;
}