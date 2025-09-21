// 处理类型
#include <iostream>

int main(void) {
    
    // 类型别名: typedef using
    typedef double wages; // wages = double
    typedef wages base, *p; // base = wages = double  p = double *

    wages a = 3.14;
    base b = 2.71;
    p pa = &a;
    p pb = &b;
    std::cout << "a: " << a << ' ' << pa << '\n' << "b: " << b << ' ' << pb << std::endl;

    using LD = long double;
    using LDP = long double *;

    LD c = 3.1415926;
    LDP pc = &c;
    std::cout << "c: " << c << ' ' << pc << std::endl;

    //
    typedef char * pstring;
    const pstring cstr = 0; // cstr: 指向char的常量指针，const属于顶层const，修饰的是指针

    // auto类型说明符: 必须有初始值；同一条语句的变量的基本类型必须一致
    auto d = 0, *pd = &d;
    // auto e = 0, f = 3.14; // 对于此实体“auto”类型是 "double"，但之前默示为 "int"C/C++(1594)

    // 复合类型，常量和auto
    int g = 0, &rg = g;
    auto gg = rg; // 推演类型是被引用的对象

    // auto一般会忽略顶层const，但是保留底层const // 引用的顶层const会被保留 // 在auto前加const可得到顶层const
    const int ci = g, &rci = ci;
    auto h = ci; // 顶层const忽略
    auto i = rci;
    auto j = &g;
    auto k = &ci; // 底层const保留

    const auto l = ci; // 显式指定顶层const

    auto &m = ci; // 引用的顶层const被保留

    // 2.5.2
    // 2.33 2.34
    gg = 42; h = 42; i = 42;
    // j = 42; k = 42; m = 42;

    //2.35
    const int n = 42;
    auto o = n;
    const auto &q = n;
    auto *r = &n;
    const auto s = n, &t = n;

    // decltype
    const int cint = 0, &rcint = cint;
    decltype(cint) u = 0;
    decltype(rcint) v = u; // decltype的推演类型是变量本身，包括引用

    int w = 42, *pw = &w, &rw = w;
    decltype(rw + 0) x; // rw + 0 返回int类型
    decltype(*pw) y = x; // *pw 返回引用类型

    // 2.5.3
    // 2.36
    int num1 = 3, num2 = 4;
    decltype(num1) num3 = num1;
    decltype((num2)) num4 = num1;
    ++num3;
    ++num4;
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << '\n' << std::endl;

    // 2.37
    decltype(num1) num5 = num1;
    decltype(num1 = num2) num6 = num1;
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num5 = " << num5 << std::endl;
    std::cout << "num6 = " << num6 << '\n' << std::endl;

    return 0;
}