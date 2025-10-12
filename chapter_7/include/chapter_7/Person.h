#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
    friend std::istream &read(std::istream &is, Person &item);
    friend std::ostream &print(std::ostream &os, const Person &item);
public:
    // 构造函数
    Person() : name(), address() {}

    explicit Person(std::string na) : name(na) {}

    Person(std::string na, std::string ad)
        : name(na), address(ad) {}

    explicit Person(std::istream &is) { read(is, *this); }
    // 操作

private:
    // 数据成员
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &item);
std::ostream &print(std::ostream &os, const Person &item);

#endif // PERSON_H