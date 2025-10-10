#include "chapter_7/Person.h"
#include <iostream>

std::istream &read(std::istream &is, Person &item) {
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &item) {
    os << item.name << " " << item.address;
    return os;
}