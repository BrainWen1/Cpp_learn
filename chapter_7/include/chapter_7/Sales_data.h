#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend std::istream &read(std::istream &is, Sales_data &item);
public:
    // 构造函数
    Sales_data() : bookNo(), units_sold(0), revenue(0.0) {}

    Sales_data(const std::string &s) : bookNo(s) {}

    Sales_data(const std::string s, const unsigned n, const double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}

    Sales_data(std::istream &is) { read(is, *this); }
    // 操作
    std::string isbn() const { return bookNo; }

    Sales_data &combine(const Sales_data &rhs);

private:
    double avg_price() const;
    // 数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::ostream &print(std::ostream &os, const Sales_data &item);
std::istream &read(std::istream &is, Sales_data &item);

#endif // SALES_DATA_H