#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {} // 默认构造函数和构造函数
    HasPtr(const HasPtr &p) : ps(new std::string(*(p.ps))), i(p.i) {} // 拷贝构造函数

    HasPtr &operator=(const HasPtr &p) { // 赋值运算符
        if (this != &p) { // 自赋值检查
            delete ps;
            ps = new std::string(*(p.ps)); // 分配新内存并拷贝数据
            i = p.i;
        }
        return *this;
    }

private:
    std::string *ps;
    int i;
};

#endif // HASPTR_H