// 命名空间的using声明
#include <iostream>
#include "Sales_data.h"

// 每个名字都需要一个独立的using声明
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main(void) {

    // 3.1
    // 1.4.1
    // 1.9
    int total = 0, n = 50;
    while(n <= 100) {
        total += n;
        n++;
    }
    cout << total << endl;

    // 1.10
    for(n = 10; n >= 0; --n) {
        cout << n << ' ';
    }
    cout << endl;

    // 1.11
    int left{0}, right{0};
    cout << "Enter two numbers: ";
    cin >> left >> right;
    if(left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }
    cout << endl;
    for(; left <= right; left++) {
        cout << left << ' ';
    }
    cout << endl;

    // 2.6.2
    // 1.20
    Sales_data temp;
    n = 3;
    while(n--) {
        cin >> temp.bookNo >> temp.units_sold >> temp.revenue;
        cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << endl;
    }
    cout << endl;

    // 1.21
    Sales_data s1, s2;
    cin >> s1.bookNo >> s1.units_sold >> s1.revenue;
    cin >> s2.bookNo >> s2.units_sold >> s2.revenue;

    temp.bookNo = s1.bookNo;
    temp.units_sold = s1.units_sold + s2.units_sold;
    temp.revenue = s1.revenue + s2.revenue;
    cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << '\n' << endl;

    // 1.22
    n = 3;
    unsigned totalNum{0};
    double totalRevenue{0.0};
    while(n--) {
        cin >> temp.bookNo >> temp.units_sold >> temp.revenue;
        totalNum += temp.units_sold;
        totalRevenue += temp.revenue;
    }
    cout << temp.bookNo << ' ' << totalNum << ' ' << totalRevenue<< ' ' << totalRevenue / totalNum << '\n' << endl;

    // 1.23 1.24 1.25
    Sales_data s;
    
    if(cin >> temp.bookNo >> temp.units_sold >> temp.revenue) {
        n = 1;
        while(cin >> s.bookNo >> s.units_sold >> s.revenue) {
            if(s.bookNo == temp.bookNo) {
                temp.units_sold += s.units_sold;
                temp.revenue += s.revenue;
                n++;
            } else {
                cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << "   " << n << " times" << endl;
                temp.bookNo = s.bookNo;
                temp.units_sold = s.units_sold;
                temp.revenue = s.revenue;
                n = 1;
            }
        }
        cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << "   " << n << " times" << endl;
    } else {
        cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}