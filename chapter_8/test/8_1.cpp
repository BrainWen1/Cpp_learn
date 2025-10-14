// IO类
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::istream &func(std::istream &is) {
    std::string str;
    while(is >> str) {
        std::cout << str;
    }

    is.clear();
    return is;
}

int main(void) {
    std::ifstream ifs;
    std::istringstream iss;

    std::string str;
    iss >> str;

    // 条件状态
    std::ios::iostate goo = std::ios::goodbit;
    std::cout << goo << " " << std::ios::failbit << " " << std::ios::eofbit
        << " " << std::ios::badbit << std::endl;
    // goodbit:0000    badbit:0001    eofbit:0010    failbit:0100

    if(iss.good()) {
        std::cout << "good" << std::endl;
    }
    if(iss.fail() && !iss.bad()) {
        std::cout << "fail" << std::endl;
    }
    if(iss.bad()) {
        std::cout << "bad" << std::endl;
    }
    if(iss.eof()) {
        std::cout << "eof" << std::endl;
    }

    std::cout << iss.rdstate() << std::endl;

    iss.clear();
    std::cout << iss.rdstate() << std::endl;

    iss.clear(std::ios::badbit);
    std::cout << iss.rdstate() << std::endl;

    iss.setstate(std::ios::failbit);
    std::cout << iss.rdstate() << std::endl;

    // 8.1.2
    // 8.1 8.2
    func(std::cin);

    // 管理输出缓冲
    std::cout << "endl" << std::endl;
    std::cout << "ends" << std::ends;
    std::cout << "flush" << std::flush;

    std::cout << std::unitbuf;
    std::cout << std::nounitbuf;

    std::ostream *old_tie = std::cin.tie(nullptr);
    std::cin.tie(&std::cerr);
    std::cin.tie(old_tie);

    return 0;
}