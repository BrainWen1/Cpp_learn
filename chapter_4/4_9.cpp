// sizeof运算符
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef struct node {
    char ch;
    int i;

    void print() {
        cout << ch << ' ' << i << endl;
    }
}node;

int main(void) {
    node nod;
    cout << sizeof(node) << ' ' << sizeof(nod) << endl;
    cout << sizeof(nod.ch) << ' ' << sizeof(node::i) << ' ' << sizeof(node::print) << endl; // print是一个函数指针

    double d = 3.14;
    double *pd = &d;
    cout << sizeof(d) << ' ' << sizeof(*pd) << ' ';
    pd = nullptr;
    cout << sizeof(*pd) << endl;
    // 编译器只需要知道 pd 的类型是 “指向 double 的指针”，就能直接得出 “解引用后是 double 类型，大小为 double 的字节数

    double &rd = d;
    cout << sizeof(rd) << endl;

    int arr[10] = {0};
    cout << sizeof(arr) << ' ' << sizeof(arr[0]) << ' ' << sizeof(arr) / sizeof(arr[0]) << endl;

    string str("Hello, world!");
    vector<int> ivec{1, 2, 3};
    cout << sizeof(string) << ' ' << sizeof(vector<int>) << endl;
    cout << sizeof(str) << ' ' << sizeof(ivec) << endl << endl;
    // 动态容器的 “对象本身” 就像一个 “增强版指针”：不仅负责指向元素存储的内存，还内置了 “记录大小、管理扩容” 的逻辑。
    // 但核心逻辑和 “指针管理数组” 一致 ———— 对象（或指针）的大小，与它所管理的元素总大小无关。

    // 4.9
    // 4.28
    cout << sizeof(char) << ' ' << sizeof(short) << ' ' << sizeof(int) << ' ' << sizeof(long) << ' '
        << sizeof(long long) << ' ' << sizeof(unsigned) << ' ' << sizeof(unsigned long) << ' ' 
        << sizeof(unsigned long long) << ' ' << sizeof(float) << ' ' << sizeof(double) << ' '
        << sizeof(long double) << endl;

    return 0;
}