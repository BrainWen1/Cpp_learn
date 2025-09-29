// 位运算符
#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main(void) {

    // 移位运算符
    int num = 6657;
    cout << bitset<sizeof(num) * 8> (num) << endl;
    cout << bitset<sizeof(num) * 8> (num << 2) << endl;

    num = -6657;
    cout << 1 << bitset<sizeof(num) * 8 - 1> ((~num) + 1) << endl;
    cout << bitset<sizeof(num) * 8> (num) << endl;
    cout << bitset<sizeof(num) * 8> (num << 2) << endl;
    cout << bitset<sizeof(num) * 8> (num >> 2) << endl << endl;

    //  位求反运算符（按位取反）
    num = 6657;
    cout << bitset<sizeof(num) * 8> (num) << endl;
    cout << bitset<sizeof(num) * 8> (~num) << endl << endl;

    // 位与、位或、位异或运算符
    cout << bitset<4> (6) << endl;
    cout << bitset<4> (2) << endl;
    cout << "-----------" << endl;
    cout << bitset<4> (6 & 2) << endl;
    cout << bitset<4> (6 | 2) << endl;
    cout << bitset<4> (6 ^ 2) << endl << endl;

    // 使用位运算符
    unsigned long quiz = 0;
    int n = 0;
    cout << "How many: ";
    cin >> n;
    while(n--) {
        cin >> num;
        quiz |= (1UL << num);
    }

    for(int i = 1; i != 31; ++i) {
        bool status = quiz & (1UL << i);
        if(status) {
            cout << "pass" << ' ';
        } else {
            cout << "fail" << ' ';
        }
    }
    cout << endl;

    quiz &= ~(1UL << num);

    for(int i = 1; i != 31; ++i) {
        bool status = quiz & (1UL << i);
        if(status) {
            cout << "pass" << ' ';
        } else {
            cout << "fail" << ' ';
        }
    }
    cout << endl;

    return 0;
}