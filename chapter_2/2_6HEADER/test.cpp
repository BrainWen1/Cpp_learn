#include <iostream>
#include "Sales_data.h"

int main(void) {

    // 2.6.3
    // 1.20
    Sales_data temp;
    int n = 3;
    while(n--) {
        std::cin >> temp.bookNo >> temp.units_sold >> temp.revenue;
        std::cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << std::endl;
    }
    std::cout << std::endl;

    // 1.21
    Sales_data s1, s2;
    std::cin >> s1.bookNo >> s1.units_sold >> s1.revenue;
    std::cin >> s2.bookNo >> s2.units_sold >> s2.revenue;

    temp.bookNo = s1.bookNo;
    temp.units_sold = s1.units_sold + s2.units_sold;
    temp.revenue = s1.revenue + s2.revenue;
    std::cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << '\n' << std::endl;

    // 1.22
    n = 3;
    unsigned totalNum{0};
    double totalRevenue{0.0};
    while(n--) {
        std::cin >> temp.bookNo >> temp.units_sold >> temp.revenue;
        totalNum += temp.units_sold;
        totalRevenue += temp.revenue;
    }
    std::cout << temp.bookNo << ' ' << totalNum << ' ' << totalRevenue<< ' ' << totalRevenue / totalNum << '\n' << std::endl;

    // 1.23 1.24 1.25
    Sales_data s;
    
    if(std::cin >> temp.bookNo >> temp.units_sold >> temp.revenue) {
        n = 1;
        while(std::cin >> s.bookNo >> s.units_sold >> s.revenue) {
            if(s.bookNo == temp.bookNo) {
                temp.units_sold += s.units_sold;
                temp.revenue += s.revenue;
                n++;
            } else {
                std::cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << "   " << n << " times" << std::endl;
                temp.bookNo = s.bookNo;
                temp.units_sold = s.units_sold;
                temp.revenue = s.revenue;
                n = 1;
            }
        }
        std::cout << temp.bookNo << ' ' << temp.units_sold << ' ' << temp.revenue << ' ' << temp.revenue / temp.units_sold << "   " << n << " times" << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }

    return 0;
}