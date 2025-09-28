// 赋值运算符
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {

    // 初始值列表作为赋值语句的右侧对象
    vector<int> ivec{1, 2};
    int k = 0;

    ivec = {0, 1, 2, 3, 4};
    // k = {3.14}; // error: 花括号列表会进行检查，存在信息丢失的风险时，会报错
    k = {666};
    cout << k << ' ' << ivec.size() << endl;

    k = {}; // 列表为空时会执行值初始化
    ivec = {};
    cout << k << ' ' << ivec.size() << endl;

    return 0;
}