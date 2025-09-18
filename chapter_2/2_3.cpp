// 复合类型
#include <iostream>

int main(void) {

    // 引用：对象的别名
    int val = 100;
    int &refval = val;

    std::cout << &val << '\n' << &refval << std::endl; // 相同地址

    // 指针
    int *p1 = &val;
    int *p2 = &refval;
    std::cout << *p1 << ' ' << *p2 << std::endl; // 100 100

    int *pnull = nullptr; // 0 NULL

    return 0;
}