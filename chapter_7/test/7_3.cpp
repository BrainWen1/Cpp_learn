// 类的其他特性
#include <iostream>
#include "chapter_7/Sales_data.h"
#include "chapter_7/Screen.h"

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    // 7.3.2
    // 7.27
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';

    // 7.3.3
    // 7.31
    class Y;

    class X {
        Y *py = nullptr;
    };

    class Y {
        X x;
    };

    return 0;
}