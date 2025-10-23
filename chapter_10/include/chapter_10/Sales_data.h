#ifndef SALES_DATA_H
#define SALES_DATA_H

#define NDEBUG

#include <string>
#include <iostream>

class Sales_data {
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend std::istream &read(std::istream &is, Sales_data &item);
public:
    // 构造函数
    Sales_data(const std::string s, const unsigned n, const double p)
        : bookNo(s), units_sold(n), revenue(n * p) {
            #ifndef NDEBUG
            std::cout << "Sales_data(const std::string s, const unsigned n, const double p)" << std::endl;
            #endif // NDEBUG
        }

    Sales_data() : Sales_data("", 0, 0.0) {
        #ifndef NDEBUG
        std::cout << "Sales_data()" << std::endl;
        #endif // NDEBUG
    }

    explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {
        #ifndef NDEBUG
        std::cout << "Sales_data(const std::string &s)" << std::endl;
        #endif // NDEBUG
    }

    explicit Sales_data(std::istream &is) : Sales_data() {
        #ifndef NDEBUG
        std::cout << "Sales_data(std::istream &is)" << std::endl;
        #endif // NDEBUG
        
        read(is, *this);
    }
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

inline double Sales_data::avg_price() const {
    if(units_sold != 0) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

#endif // SALES_DATA_H