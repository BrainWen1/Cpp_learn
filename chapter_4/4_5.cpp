// 递增和递减运算符
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

using I_vec = vector<int>;

int main(void) {

    //
    int a = 0;
    ++a += 1; // 前置递变运算符将递变后的对象作为左值返回
    cout << a << endl;

    cout << a++ << ' '; // 后置递变运算符将递变前的值的副本作为右值返回
    cout << a << endl;

    // 混用解引用和递变运算符
    I_vec ivec{0, 1, 2, 3, 4, 5};
    auto pbeg = ivec.cbegin();
    cout << *pbeg++ << ' '; // ++ 优先级大于 *
    cout << *pbeg << endl;

    return 0;
}