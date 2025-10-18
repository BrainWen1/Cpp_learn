// 额外的string操作
#include <iostream>
#include <string>
#include <vector>

void replace(std::string &s1, std::string &s2, std::string &s3) {
    size_t len = s2.size();

    for(size_t i = 0; i != s1.size(); ++i) {
        if(s1.at(i) == s2.at(0) && s1.substr(i, len) == s2) {
            s1.erase(s1.begin() + i, s1.begin() + i + len);

            for(size_t j = 0; j != len; ++j) {
                s1.insert(s1.begin() + i, s3[j]);
            }
        }
    }
}

int main(void) {
    // 9.5.1
    // 9.41
    std::vector<char> cvec{'h', 'e', 'l', 'l', 'o', '!'};

    std::string str(&cvec[0], cvec.size());
    std::cout << str << std::endl;

    // 9.42
    std::string s;
    s.reserve(100);

    // 9.5.2
    // 9.43
    std::string s1("hello, world! wowd"), s2("wo"), s3("00");

    std::cout << s1 << std::endl;
    replace(s1, s2, s3);
    std::cout << s1 << std::endl;

    return 0;
}