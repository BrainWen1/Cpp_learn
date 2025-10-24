// 再探迭代器
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <deque>

void print(std::vector<int> &ivec) {
    for(const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print(std::list<int> &il) {
    for(const auto &i : il) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print(std::deque<int> &ideq) {
    for(const auto &i : ideq) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    // 插入迭代器
    std::vector<std::string> svec;
    auto back_it = std::back_inserter(svec);
    back_it = "Hello";
    *back_it = "World"; // * ++ 没有实际意义

    std::cout << svec.size() << ": ";
    for(const auto &s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    auto ins_it = std::inserter(svec, svec.begin());
    *ins_it = "Hi";
    std::cout << svec.size() << ": ";
    for(const auto &s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    auto ins_it2 = std::inserter(svec, svec.end() - 1);
    *ins_it2 = "C++";
    std::cout << svec.size() << ": ";
    for(const auto &s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // 10.4.1
    // 10.27
    std::list<int> il;
    std::vector<int> ivec = {1, 2, 2, 3, 4, 4, 5, 5, 5, 6};

    std::unique_copy(ivec.begin(), ivec.end(), std::back_inserter(il));

    std::cout << "il: ";
    for(const auto &i : il) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "ivec: ";
    for(const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 10.28
    ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> ideq;
    std::vector<int> ivec2;
    il.clear();

    std::cout << "------------------" << std::endl;
    std::copy(ivec.begin(), ivec.end(), std::front_inserter(il));
    print(il);
    il.clear();
    std::copy(ivec.begin(), ivec.end(), std::back_inserter(il));
    print(il);
    il.clear();
    auto il_beg = il.begin();
    std::copy(ivec.begin(), ivec.end(), std::inserter(il, ++il_beg));   
    print(il);

    std::cout << "------------------" << std::endl;
    std::copy(ivec.begin(), ivec.end(), std::front_inserter(ideq));
    print(ideq);
    ideq.clear();
    std::copy(ivec.begin(), ivec.end(), std::back_inserter(ideq));
    print(ideq);
    ideq.clear();
    auto ideq_beg = ideq.begin();
    ideq.push_back(0); // 确保++ideq_beg有效
    std::copy(ivec.begin(), ivec.end(), std::inserter(ideq, ++ideq_beg));
    print(ideq);

    std::cout << "------------------" << std::endl;
    std::copy(ivec.begin(), ivec.end(), std::back_inserter(ivec2));
    print(ivec2);
    ivec2.clear();
    std::copy(ivec.begin(), ivec.end(), std::inserter(ivec2, ivec2.begin()));
    print(ivec2);

    // iostream迭代器

    return 0;
}