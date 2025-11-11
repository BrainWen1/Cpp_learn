// 拷贝控制
#include "chapter_13/StrBlob.h"
#include <iostream>
#include <string>
#include <vector>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }

    X &operator=(const X&) {
        std::cout << "X &operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

// 13.1.4
// 13.17
class number {
public:
    number() : mysn(++i) {} // 每创建一个对象，mysn都会被赋予一个唯一的序号
    number(const number &n) : mysn(++i) {} // 拷贝构造函数，同样分配一个新的序号

    static size_t i; // 静态数据成员, 所有对象共享
    size_t mysn;
};

size_t number::i = 0;

void f(const number &s) {
    std::cout << s.mysn << std::endl;
}

// 13.1.6
// 13.18
class Employee {
public:
    Employee() : id(++id_generator) {} // 默认构造函数
    Employee(const std::string &emp_name) : name(emp_name), id(++id_generator) {}

    Employee(const Employee &e) : name(e.name), id(++id_generator) {} // 拷贝构造函数

    Employee &operator=(const Employee &e) { // 赋值运算符
        if (this != &e) {
            name = e.name;
        }
        return *this;
    }

private:
    static size_t id_generator;
    std::string name;
    size_t id;
};

size_t Employee::id_generator = 0;

int main(void) {
    // 13.1.1
    // 13.3
    StrBlob sb1{"Hello", "World", "from", "StrBlob"};
    StrBlob sb2 = sb1; // 使用拷贝构造函数
    sb2.push_back("C++");

    StrBlobPtr ptr1 = sb1.begin();
    StrBlobPtr ptr2 = sb2.begin();

    std::cout << "ptr1: " << std::endl;
    for (size_t i = 0; i != sb1.size(); ++i, ptr1.increase()) {
        std::cout << ptr1.derefer() << " ";
    }
    std::cout << std::endl;

    std::cout << "ptr2: " << std::endl;
    for (size_t i = 0; i != sb2.size(); ++i, ptr2.increase()) {
        std::cout << ptr2.derefer() << " ";
    }
    std::cout << std::endl;

    // 13.1.2
    // 13.7
    StrBlob sb3{"HasPtr", "class", "test"};
    StrBlob sb4;
    sb4 = sb3; // 使用默认的赋值运算符
    StrBlobPtr ptr3 = sb4.begin();
    for (size_t i = 0; i != sb4.size(); ++i, ptr3.increase()) {
        std::cout << ptr3.derefer() << " ";
    }
    std::cout << std::endl;

    // StrBlobPtr ptr4;
    // ptr4 = ptr3; // 使用默认的赋值运算符
    // std::cout << "ptr4: : " << ptr4.derefer() << std::endl;
    // for (size_t i = 0; i != sb4.size(); ++i, ptr4.increase()) {
    //     std::cout << ptr4.derefer() << " ";
    // }
    // std::cout << std::endl;

    // 13.11
    {
        StrBlob sb5{"Temporary", "StrBlob", "object"};
        StrBlobPtr ptr5 = sb5.begin();
    }

    // 13.13
    {
        std::cout << "-------------------------------" << std::endl;
        X x1;
        X x2 = x1; // 调用拷贝构造函数
        X x3;
        x3 = x1;   // 调用赋值运算符

        X *px = new X();
        X *px2 = new X(*px); // 调用拷贝构造函数
        *px2 = x1;           // 调用赋值运算符
        delete px;
        delete px2;

        std::vector<X> vec;
        vec.push_back(x1); // 调用拷贝构造函数
    }

    // 13.1.4
    // 13.17
    std::cout << "-------------------------------" << std::endl;
    number a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}