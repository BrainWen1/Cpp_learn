// 构造函数再探
#include <iostream>
#include "chapter_7/Sales_data.h"
#include <string>
#include <vector>

// 7.42
class Employee {
    friend std::istream &read(std::istream &is, Employee &item);
public:
    Employee(std::string na, std::string se, unsigned ag)
        : name(na), sex(se), age(ag) {
            #ifndef NDEBUG
            std::cout << "Employee(std::string na, std::string se, unsigned ag)" << std::endl;
            #endif // NDEBUG
        }

    Employee() : Employee("", "", 0) {
        #ifndef NDEBUG
        std::cout << "Employee()" << std::endl;
        #endif // NDEBUG
    }

    Employee(std::istream &is) : Employee() {
        #ifndef NDEBUG
        std::cout << "Employee(std::istream &is)" << std::endl;
        #endif // NDEBUG

        read(is, *this);
    }
private:
    std::string name;
    std::string sex;
    unsigned age = 0;
};

std::istream &read(std::istream &is, Employee &item) {
    is >> item.name >> item.sex >> item.age;
    return is;
}

// 7.43
class NoDefault {
public:
    NoDefault(int val) : i(val) {}

private:
    int i = 0;
};

class C {
public:
    C() : nd(0) {}

private:
    NoDefault nd;
};

// 7.5.6
// 7.53
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}

    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    constexpr bool any() { return hw || io || other; }

    void set_hw(bool b) { hw = b; }

    void set_io(bool b) { io = b; }

    void set_other(bool b) { other = b; }
private:
    bool hw;
    bool io;
    bool other;
};

int main(void) {
    // 7.5.2
    // 7.41
    Sales_data s1;
    Sales_data s2("hello");
    Sales_data s3("hi", 12, 9.90);
    Sales_data s4(std::cin);

    // 7.42
    Employee e1;
    Employee e2("Brian", "man", 19);
    Employee e3(std::cin);

    // 7.5.3
    // 7.43
    // std::vector<NoDefault> vec1(10);
    std::vector<C> vec2(10);

    // explicit
    // Sales_data item1 = std::string("hello");
    Sales_data item1(std::string("hello"));
    item1.combine(Sales_data("hi"));
    item1.combine(static_cast<Sales_data> (std::string("hiya")));

    print(std::cout, item1);

    return 0;
}