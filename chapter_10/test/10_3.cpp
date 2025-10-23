// 定制操作
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "chapter_10/Sales_data.h"

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

std::ostream &print(const std::vector<std::string> &svec) {
    for(const auto &mem : svec) {
        std::cout << mem << " ";
    }
    return std::cout;
}

std::ostream &print(const std::vector<Sales_data> &vec) {
    for(const auto &item : vec) {
        print(std::cout, item) << std::endl;
    }
    return std::cout;
}

void elimDups(std::vector<std::string> &svec) {
    std::sort(svec.begin(), svec.end());
    auto end_unique = std::unique(svec.begin(), svec.end());
    svec.erase(end_unique, svec.end());
}

bool compareIsbn(const Sales_data &item1, const Sales_data &item2) {
    return item1.isbn() < item2.isbn();
}

bool check_size(const std::string &s) {
    constexpr std::size_t sz = 5;
    return s.size() >= sz;
}

void biggies(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDups(svec);
    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) -> bool {
        return s1.size() < s2.size();
    });

    auto wc = std::find_if(svec.begin(), svec.end(), [sz](const std::string &s) -> bool {
        return s.size() >= sz;
    });
    auto count = svec.end() - wc;
    std::cout << count << " words of length " << sz << " or longer" << std::endl;
    std::for_each(wc, svec.end(), [](const std::string &s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}

void biggies_1(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDups(svec);
    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) -> bool {
        return s1.size() < s2.size();
    });

    auto wc = std::partition(svec.begin(), svec.end(), [sz](const std::string &s) -> bool {
        return s.size() < sz;
    });
    auto count = svec.end() - wc;
    std::cout << count << " words of length " << sz << " or longer" << std::endl;
    std::for_each(wc, svec.end(), [](const std::string &s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}

void biggies_2(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDups(svec);
    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) -> bool {
        return s1.size() < s2.size();
    });

    auto wc = std::stable_partition(svec.begin(), svec.end(), [sz](const std::string &s) -> bool {
        return s.size() < sz;
    });
    auto count = svec.end() - wc;
    std::cout << count << " words of length " << sz << " or longer" << std::endl;
    std::for_each(wc, svec.end(), [](const std::string &s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}

int main(void) {
    // 谓词
    std::vector<std::string> svec{"the", "quick", "red", "fox", "jumps",
                                  "over", "the", "slow", "red", "turtle"};
    print(svec) << std::endl;
    // 按长度排序
    std::sort(svec.begin(), svec.end(), isShorter);
    print(svec) << std::endl;
    
    // 排序算法
    std::cout << "-------------------------" << std::endl;
    elimDups(svec); // 按字典序重排并去重
    print(svec) << std::endl;

    std::stable_sort(svec.begin(), svec.end(), isShorter); // 按长度重排，保持长度相等元素的字典序
    print(svec) << std::endl;

    // 10.3.1
    // 10.12
    std::cout << "-------------------------" << std::endl;
    std::vector<Sales_data> sales_vec{
        Sales_data("978-7-121-15535-2", 4, 59.00),
        Sales_data("978-7-121-25535-2", 2, 59.00),
        Sales_data("978-7-121-05536-9", 1, 75.00),
        Sales_data("978-7-121-16537-6", 5, 45.00),
        Sales_data("978-7-121-15536-9", 3, 75.00)
    };
    std::stable_sort(sales_vec.begin(), sales_vec.end(), compareIsbn);
    print(sales_vec);

    // 10.13
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };

    auto mid = std::partition(svec.begin(), svec.end(), check_size);
    print(svec) << std::endl;
    for(auto iter = svec.begin(); iter != mid; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << *mid << std::endl;

    //  lambda表达式
    // find_if
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    print(svec) << std::endl;

    auto it = std::find_if(svec.begin(), svec.end(), [](const std::string &s) -> bool {
        constexpr std::size_t sz = 5;
        return s.size() >= sz;
    });
    if(it != svec.end()) {
        std::cout << *it << std::endl;
    }

    // 使用捕获列表
    std::cout << "-------------------------" << std::endl;
    constexpr std::size_t sz = 4;
    it = std::find_if(svec.begin(), svec.end(), [sz](const std::string &s) -> bool {
        return s.size() == sz;
    });
    if(it != svec.end()) {
        std::cout << *it << std::endl;
    }

    // for_each
    std::cout << "-------------------------" << std::endl;
    
    std::for_each(svec.begin(), svec.end(), [](const std::string &s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;

    // 10.3.2
    // 10.14
    std::cout << "-------------------------" << std::endl;
    auto a = [](const int &i, const int &j) -> int {
        return i + j;
    };
    std::cout << a(3, 5) << " ";

    // 10.15
    int num = 7;
    auto b = [num](const int &i) -> int {
        return num + i;
    };
    std::cout << b(10) << std::endl;

    // 10.16
    std::cout << "-------------------------" << std::endl;
    print(svec) << std::endl;
    biggies(svec, 4);

    // 10.17
    std::cout << "-------------------------" << std::endl;
    sales_vec = std::vector<Sales_data>{
        Sales_data("978-7-121-15535-2", 4, 59.00),
        Sales_data("978-7-121-25535-2", 2, 59.00),
        Sales_data("978-7-121-05536-9", 1, 75.00),
        Sales_data("978-7-121-16537-6", 5, 45.00),
        Sales_data("978-7-121-15536-9", 3, 75.00)
    };
    std::stable_sort(sales_vec.begin(), sales_vec.end(), [](const Sales_data &item1, const Sales_data &item2) -> bool {
        return item1.isbn() < item2.isbn();
    });
    print(sales_vec);

    // 10.18
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    biggies_1(svec, 4);

    // 10.19
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    biggies_2(svec, 4);

    // 值捕获
    std::cout << "-------------------------" << std::endl;
    int val = 42;
    auto f = [val]() mutable -> int { return val; };
    std::cout << f() << std::endl;
    val = 0;
    std::cout << f() << std::endl;

    // 引用捕获
    std::cout << "-------------------------" << std::endl;
    auto f2 = [&val]() -> int { return val; };
    std::cout << f2() << std::endl;
    val = 10;
    std::cout << f2() << std::endl;

    // 隐式捕获
    std::cout << "-------------------------" << std::endl;
    int v1 = 1, v2 = 2;
    auto f3 = [=]() -> int { return v1 + v2; };
    std::cout << f3() << std::endl;
    v1 = 10; v2 = 20;
    std::cout << f3() << std::endl;

    // 混合捕获
    std::cout << "-------------------------" << std::endl;
    int v3 = 3, v4 = 4;
    auto f4 = [=, &v4]() -> int { return v3 + v4; };
    std::cout << f4() << std::endl;
    v3 = 30; v4 = 40;
    std::cout << f4() << std::endl;

    // 可变lambda
    std::cout << "-------------------------" << std::endl;

    return 0;
}