// Strblob.h
#include "chapter_12/StrBlob.h"

// StrBlob member functions

void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

const Const_StrBlobPtr StrBlob::begin() const { return Const_StrBlobPtr(*this); }
const Const_StrBlobPtr StrBlob::end() const { return Const_StrBlobPtr(*this, data->size()); }

// StrBlobPtr member functions

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if(ret == nullptr) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

std::string &StrBlobPtr::derefer() const {
    auto p = check(curr, "dereference past end");
    return p->at(curr);
}

StrBlobPtr &StrBlobPtr::increase() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// Const_StrBlobPtr member functions

std::shared_ptr<std::vector<std::string>> Const_StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if(ret == nullptr) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

const std::string &Const_StrBlobPtr::derefer() const {
    auto p = check(curr, "dereference past end");
    return p->at(curr);
}

Const_StrBlobPtr &Const_StrBlobPtr::increase() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}