// 类型转换
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 显式转换
    // 命名的强制类型转换
    // static_cast
    int i = 4, j = 3;
    double d = static_cast<double> (i) / j;
    cout << d << endl;

    void *p = &d;
    double *pd = static_cast<double*> (p);

    // const_cast
    int *const pi = &i;
    int *pii = const_cast<int*> (pi);

    // reinterpret_cast
    char *pc = reinterpret_cast<char*> (pii);

    // 旧式的强制类型转换
    char *pcc = (char*)pi; // 等价于reinterpret_cast

    return 0;
}