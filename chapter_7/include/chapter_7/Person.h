#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
    // 成员函数


    // 数据成员
    std::string name;
    std::string address;
};

std::istream &read(std::istream &is, Person &item);
std::ostream &print(std::ostream &os, const Person &item);

#endif // PERSON_H