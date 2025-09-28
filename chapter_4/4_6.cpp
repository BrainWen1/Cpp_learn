// 成员访问运算符
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct node {
    int value;
    struct node *next;
}node;

int main(void) {

    // 点运算符 箭头运算符
    node a = {1, nullptr};
    node b = {2, &a};

    node *pa = &a;
    node *pb = &b;

    cout << a.value << ' ' << b.value << endl; // -> 优先级大于 *
    cout << (b.next)->value << ' ' << (*(b.next)).value << ' ' << pa->value << ' ' << (*pb).value << endl;

    return 0;
}