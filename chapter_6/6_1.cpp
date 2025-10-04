// 函数基础
#include <iostream>
#include "chapter_6/chapter_6.h"

using std::cin;
using std::cout;
using std::endl;

// 6.1.1

int main(void) {

    int num = 0;
    cin >> num;
    cout << fact(num) << endl;

    cout << fact_x() << endl;

    cin >> num;
    cout << absolute(num) << endl;

    for(int i = 0; i != 10; ++i) {
        cout << count_calls() << ' ';
    }
    cout << endl;

    return 0;
}