// 简单语句
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 空语句
    ;
    int a = 0;
    while(cin >> a && a != 0)
        ;
    
    // 复合语句（块）
    a = 5;
    int total = 0;
    while(a--) {
        cout << a << ' ';
        total += a;
    }
    cout << total << endl;

    // 空块
    {}

    // 5.1
    // 5.3
    int sum = 0, val = 1;
    while(sum += val, val++ < 10);
    cout << sum << ' ';

    sum = 0, val = 1;
    while(sum += val, ++val, val <= 10);
    cout << sum << ' ';

    return 0;
}