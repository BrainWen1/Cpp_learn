#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
    // 构造函数
    Person() : name(), address() {}

    Person(std::string na) : name(na) {}

    Person(std::string na, std::string ad)
        : name(na), address(ad) {}

    // 成员函数


    // 数据成员
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &item);
std::ostream &print(std::ostream &os, const Person &item);

#endif // PERSON_H