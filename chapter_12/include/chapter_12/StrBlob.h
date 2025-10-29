#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <stdexcept> // std::out_of_range

class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob() = default;
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &s) { data->push_back(s); }
    void pop_back();

    std::string& front();
    std::string& back();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg);
};

void StrBlob::check(size_type i, const std::string &msg) {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

#endif // STRBLOB_H
