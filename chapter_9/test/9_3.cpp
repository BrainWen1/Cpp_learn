// 顺序容器操作
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <algorithm>
#include <iterator>

std::ostream_iterator<std::string> &print(const std::vector<std::string> &svec, 
std::ostream_iterator<std::string> &oiter) {
    
    std::cout << svec.size() << std::endl;
    std::copy(svec.begin(), svec.end(), oiter);
    std::cout << std::endl;

    return oiter;
}

// 返回第一个string位置的迭代器，没有查找到则返回尾后迭代器
std::forward_list<std::string>::iterator find_from(std::forward_list<std::string> &fls, std::string &s1, std::string &s2) {
    auto prev = fls.before_begin();
    auto curr = fls.begin();

    while(curr != fls.end()) {
        if(*curr == s1) {
            fls.insert_after(curr, s2);
            return curr;
        } else {
            ++prev;
            ++curr;
        }
    }
    fls.insert_after(prev, s2);
    return curr;
}

int main(void) {
    // 向顺序容器添加元素
    std::vector<std::string> svec;
    svec.emplace_back(5, 'a');
    svec.emplace_back("hello!");

    std::ostream_iterator<std::string> oiter(std::cout, " ");
    print(svec, oiter);

    svec.insert(svec.end() - 1, "fff");
    print(svec, oiter);

    svec.insert(svec.end(), 3, "hhh");
    print(svec, oiter);

    // 9.3.1
    // 9.18
    std::deque<std::string> dq;
    std::string str;
    while(std::cin >> str) {
        dq.push_back(str);
    }
    for(auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::copy(dq.begin(), dq.end(), oiter);
    std::cout << std::endl;

    // 9.19
    std::list<std::string> lst;
    std::string str;
    while(std::cin >> str) {
        lst.push_back(str);
    }
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 9.20
    std::list<int> il{0, 2, 3, 4, 5, 5, 7, 8};
    std::deque<int> odd, even;

    for(const int &e : il) {
        if(e % 2 == 1) {
            odd.push_back(e);
        } else {
            even.push_back(e);
        }
    }
    std::ostream_iterator<int> ioit(std::cout, " ");

    std::copy(odd.begin(), odd.end(), ioit); std::cout << std::endl;
    std::copy(even.begin(), even.end(), ioit); std::cout << std::endl;

    // 访问元素
    if(!il.empty()) {
        il.front() = 666;
        il.back() = 921;
        std::copy(il.begin(), il.end(), ioit); std::cout << std::endl;
    }

    std::cout << odd.at(0) << std::endl; // << " " << even.at(4); "std::out_of_range"

    // 9.3.2
    // 9.24
    std::vector<int> ivec;
    // int a = ivec.at(0);
    // int b = ivec[0];
    // int c = ivec.front();
    auto d = ivec.begin();

    // 删除元素
    ivec = std::vector<int> {0, 1, 2, 3, 4, 5, 6, 7};
    std::copy(ivec.begin(), ivec.end(), ioit); std::cout << std::endl;

    ivec.pop_back();
    std::copy(ivec.begin(), ivec.end(), ioit); std::cout << std::endl;

    ivec.erase(ivec.begin() + 2);
    std::copy(ivec.begin(), ivec.end(), ioit); std::cout << std::endl;

    ivec.erase(ivec.begin() + 1, ivec.begin() + 3);
    std::copy(ivec.begin(), ivec.end(), ioit); std::cout << std::endl;

    // 9.3.3
    // 9.26
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    ivec.clear(); il.clear();
    std::copy(std::begin(ia), std::end(ia), std::back_inserter(ivec));
    std::copy(std::begin(ia), std::end(ia), std::back_inserter(il));
    
    for(auto it = il.begin(); it != il.end();) {
        if(*it % 2 == 1) {
            it = il.erase(it);
        } else {
            ++it;
        }
    }

    for(auto it = ivec.begin(); it != ivec.end();) {
        if(*it % 2 == 0) {
            it = ivec.erase(it);
        } else {
            ++it;
        }
    }

    std::copy(il.begin(), il.end(), ioit); std::cout << std::endl;
    std::copy(ivec.begin(), ivec.end(), ioit); std::cout << std::endl;

    // 特殊的forward_list操作
    // 9.3.4
    // 9.27
    std::forward_list<int> fl{0, 1, 1, 2, 3, 8, 10, 4, 7};
    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while(curr != fl.end()) {
        if(*curr % 2 == 1) {
            curr = fl.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
    std::copy(fl.begin(), fl.end(), ioit); std::cout << std::endl;

    // 9.28
    std::forward_list<std::string> fls{"yoyo", "hiya", "hi","world", "etc"};
    std::string s1("hi"), s2("hello");

    std::copy(fls.begin(), fls.end(), oiter); std::cout << std::endl;
    find_from(fls, s1, s2);
    std::copy(fls.begin(), fls.end(), oiter); std::cout << std::endl;

    std::forward_list<std::string> fls2{"yoyo", "hiya", "hi","world", "etc"};
    std::copy(fls2.begin(), fls2.end(), oiter); std::cout << std::endl;
    find_from(fls2, s2, s1);
    std::copy(fls2.begin(), fls2.end(), oiter); std::cout << std::endl;

    // 9.3.6
    // 9.31
    il = std::list<int> {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto lit = il.begin();

    while(lit != il.end()) {
        if(*lit % 2 == 1) {
            il.insert(lit, *lit);
            ++lit;
        } else {
            lit = il.erase(lit);
        }
    }
    std::copy(il.begin(), il.end(), ioit); std::cout << std::endl << std::endl;

    // 9.33
    ivec = std::vector<int> {1, 2, 3};

    std::copy(ivec.begin(), ivec.end(), ioit);
    std::cout << std::endl;

    auto begin = ivec.begin();
    while(begin != ivec.end()) {
        ++begin;
        begin = ivec.insert(begin, 42);
        ++begin;
    }

    std::copy(ivec.begin(), ivec.end(), ioit);
    std::cout << std::endl;

    return 0;
}