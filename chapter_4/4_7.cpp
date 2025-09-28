// 条件运算符
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void) {

    // cond ? expr1 : expr2; 要求expr1和expr2类型相同或可以转换为某个公共类型
    unsigned grade = 62;
    string finalgrade = (grade > 60) ? "pass" : "fail";
    cout << finalgrade << endl;

    // 右结合律
    grade = 82;
    finalgrade = (grade > 90) ? "high" : (grade > 60) ? "pass" : "fail";
    cout << finalgrade << endl;

    // 4.7
    // 4.21
    vector<int> ivec{-1, 4, 10, 12, 7, 23, 99};
    for(auto &e: ivec) {
        (e % 2 == 1 || e % 2 == -1) ? (e <<= 1) : e;
    }

    for(auto e: ivec) {
        cout << e << ' ';
    }
    cout << endl;

    return 0;
}