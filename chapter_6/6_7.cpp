// 函数指针
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

inline void print(int val) {
    cout << val;
    return;
}

inline void print(char ch) {
    cout << ch;
    return;
}

inline void print_func(int val, void (*pf)(int)) {
    pf(val);
    return;
}

// 6.7
// 6.55
inline int addi(int a, int b) { return a + b; }
inline int subs(int a, int b) { return a - b; }
inline int mult(int a, int b) { return a * b; }
inline int divi(int a, int b) { return a / b; }


int main(void) {

    // 函数类型 声明函数指针
    void (*p1)(int) = print;
    void (*p2)(int) = &print;

    p1(1);
    (*p1)(2);
    p2(3);
    (*p2)(4);

    p1 = 0;
    p2 = nullptr;

    // 函数指针形参
    cout << " ";
    print_func(5, print);

    // 简化声明
    typedef void func(int);
    typedef void (*pfunc)(int);
    typedef decltype(print_func) Func;
    typedef decltype(print_func) *pFunc;

    func *p3 = print;
    pfunc p4 = print;
    Func *p5 = print_func;
    pFunc p6 = print_func;
    p3(6); p4(7); p5(8, print); p6(9, print);
    print('\n');

    // 返回指向函数的指针
    // 直接声明
    void (*func1(int, int))(int);

    // 类型别名
    using f1 = void (int);
    using pf1 = void (*)(int);

    f1 *func2(int, int);
    pf1 func3(int, int);

    // 尾置返回类型
    auto func4(int, int) -> void (*)(int);

    // 6.7
    // 6.54
    int fun(int, int);
    vector<int (*)(int, int)> pvec(4, nullptr);

    // 6.55
    pvec[0] = addi; pvec[1] = subs; pvec[2] = mult; pvec[3] = divi;

    int a = 5, b = 2;
    for(decltype(pvec.size()) i = 0; i != pvec.size(); ++i) {
        cout << pvec[i](a, b) << " ";
    }
    cout << endl;

    return 0;
}