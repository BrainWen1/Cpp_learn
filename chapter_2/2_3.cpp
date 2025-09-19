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

    // int *pnull = nullptr; // 0 NULL

    // int zero = 0;
    // int *pz = zero; // 不能用变量给指针赋值

    // void *：可以存放任意对象的地址，但是无法直接访问指向的对象
    double d = 3.1415926536;
    void *pd = &d;
    std::cout << *((double *)pd) << std::endl;

    // 2.3.2
    // 2.18
    int num = 666;
    int *pnum = &num;
    int foo = 123;
    std::cout << pnum << ' ' << *pnum << std::endl;
    pnum = &foo;
    *pnum = 234;
    std::cout << pnum << ' ' << foo << std::endl;

    // 理解复合类型的声明：基本数据类型 + 声明符
    // 定义多个变量 二级指针
    int ival = 1024, *pi = &ival, **ppi = &pi;
    std::cout << ival << ' ' << *pi << ' ' << **ppi << std::endl;

    // 指向指针的引用
    int *&rp = pi;
    *rp = 2025;
    std::cout << ival << std::endl;

    return 0;
}