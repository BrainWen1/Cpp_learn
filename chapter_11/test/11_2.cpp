// 关联容器概述
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "chapter_11/Sales_data.h"
#include <list>
#include <utility>
#include <fstream>
#include <utility>

void print(const std::set<int>& iset) {
    for (const auto& elem : iset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(const std::multiset<int>& imset) {
    for (const auto& elem : imset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(const std::vector<std::string>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(const std::vector<std::pair<std::string, int>>& vec_pair) {
    for (const auto& p : vec_pair) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << std::endl;
}

class familys {
public:
    familys() = default;
    familys(const std::vector<std::string> &lastnames) {
        for (const auto &name : lastnames) {
            members.emplace(name, std::vector<std::string>{});
        }
    }

    ~familys() = default;

    void add_child(const std::string &lastname, const std::string &child) {
        if (members.empty() || members.find(lastname) == members.end()) {
            std::cerr << "No family exists to add a child to." << std::endl;
            return;
        }
        members.find(lastname)->second.push_back(child);
    }

    void add_family(const std::string &lastname, const std::vector<std::string> &children = {}) {
        members.emplace(lastname, children);
    }

    void print() const {
        for (const auto &fam : members) {
            std::cout << "Family " << fam.first << ": ";
            for (const auto &child : fam.second) {
                std::cout << child << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::map<std::string, std::vector<std::string>> members;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main(void) {
    // 初始化 multimap 或 multiset
    std::vector<int> ivec{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    std::set<int> iset(ivec.cbegin(), ivec.cend());
    std::multiset<int> imset(ivec.cbegin(), ivec.cend());

    print(iset);
    print(imset);

    // 11.2.1
    // 11.7
    std::cout << "------------------------" << std::endl;
    familys fam({"Smith", "Johnson"});
    fam.add_child("Smith", "John");
    fam.add_child("Johnson", "Alice");
    fam.add_family("Williams", {"Bob", "Carol"});

    fam.print();

    // 11.8
    std::vector<std::string> set_vec{"Anderson", "Brown", "Davis", "Brown", "Miller", "Wilson", "Davis"};

    std::sort(set_vec.begin(), set_vec.end());
    auto end_unique = std::unique(set_vec.begin(), set_vec.end());
    set_vec.erase(end_unique, set_vec.end());

    print(set_vec);

    // 使用关键字类型的比较函数
    std::multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);

    // 11.2.2
    // 11.10
    std::map<std::vector<int>::iterator, int> mp1;
    std::map<std::list<int>::iterator, int> mp2;

    std::list<int> ilist{1, 2, 3, 4, 5};
    // mp2.emplace(ilist.begin(), 10);
    // mp2.emplace(ilist.end(), 20);

    mp1.emplace(ivec.begin(), 30);
    mp1.emplace(ivec.end(), 40);

    // 11.11
    std::cout << "------------------------" << std::endl;
    std::multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore2(compareIsbn);

    // pair类型
    std::map<std::string, std::pair<int, double>> sales_data;
    sales_data["Book1"] = std::make_pair(10, 29.99);
    sales_data["Book2"] = std::make_pair(5, 19.99);

    // 11.2.3
    // 11.12
    std::string str;
    int val;
    std::vector<std::pair<std::string, int>> vec_pair;
    
    std::ifstream infile("../test/txt/11_2.txt");   
    std::pair<std::string, int> p;
    while(infile >> str >> val) {
        p = std::make_pair(str, val);
        vec_pair.push_back(p);
    }

    print(vec_pair);

    // 11.13
    std::cout << "------------------------" << std::endl;
    std::pair<std::string, int> p1("example", 42);
    std::pair<std::string, int> p2 = {"Example", 1024};
    vec_pair.push_back(p1);
    vec_pair.push_back(p2);
    print(vec_pair);

    // 11.14
    std::cout << "------------------------" << std::endl;
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> members;

    members["Smith"].push_back(std::make_pair("John", "20060509"));
    members["Smith"].push_back(std::make_pair("Jane", "20070315"));
    members["Johnson"].push_back(std::make_pair("Alice", "20120120"));

    for (const auto &fam : members) {
        std::cout << "Family " << fam.first << ":\n";
        for (const auto &member : fam.second) {
            std::cout << "  Name: " << member.first << ", Relation: " << member.second << std::endl;
        }
    }

    return 0;
}
