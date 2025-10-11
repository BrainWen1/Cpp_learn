// 访问控制与封装
#include <iostream>
#include "chapter_7/Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main(void) {
    // 7.2.1
    // 7.21
    Sales_data s1("0-201-78345-X", 2, 25.00);
    Sales_data s2("0-201-78345-X", 6, 12.95);
    Sales_data s3("0-411-80992-X", 1, 35.50);

    Sales_data s4 = add(s1, s2);
    print(cout, s1) << endl;
    print(cout, s2) << endl;
    print(cout, s3) << endl;
    print(cout, s4) << endl;

    Sales_data s5;
    read(cin, s5);
    print(cout, s5);

    return 0;
}