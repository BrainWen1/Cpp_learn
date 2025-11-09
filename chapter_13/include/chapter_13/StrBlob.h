#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept> // std::out_of_range

class StrBlobPtr;
class Const_StrBlobPtr; // 前向声明

// // // // StrBlob // // // //

class StrBlob {
    friend class StrBlobPtr; // 让 StrBlobPtr 访问 StrBlob 的私有成员
    friend class Const_StrBlobPtr;
public:
    using size_type = std::vector<std::string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
    StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) {} // 拷贝构造函数

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s); }
    void pop_back();

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

    StrBlobPtr begin() ;
    StrBlobPtr end();
    const Const_StrBlobPtr begin() const;
    const Const_StrBlobPtr end() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

// // // // StrBlobPtr // // // //

class StrBlobPtr {
public:
    StrBlobPtr() : wptr(), curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string &derefer() const;
    StrBlobPtr &increase();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

// // // // Const StrBlobPtr // // // //

class Const_StrBlobPtr {
public:
    Const_StrBlobPtr() : wptr(), curr(0) {}
    Const_StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

    const std::string &derefer() const;
    Const_StrBlobPtr &increase();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
#endif // STRBLOB_H
