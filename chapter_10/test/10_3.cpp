// 定制操作
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "chapter_10/Sales_data.h"
#include <functional>

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

bool check_size_1(const std::string &s, std::string::size_type sz = 5) {
    return s.size() >= sz;
}

bool check_size_2(const int val, std::string &s) {
    if(val <= 0) {
        return false;
    } else {
        auto num = static_cast<decltype(s.size())> (val);
        return num > s.size();
    }
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

void biggies_3(std::vector<std::string> &svec, std::vector<std::string>::size_type sz) {
    elimDups(svec);
    std::stable_sort(svec.begin(), svec.end(), isShorter);

    auto f = std::bind(check_size_1, std::placeholders::_1, sz);

    auto wc = std::partition(svec.begin(), svec.end(), f);

    auto count = wc - svec.begin();
    std::cout << count << " words of length " << sz << " or longer" << std::endl;
    std::for_each(svec.begin(), wc, [](const std::string &s) -> void {
        std::cout << s << " ";
    });
    std::cout << std::endl;
}

void print_string(const std::string &s1, const std::string &s2, const std::string &s3) {
    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
}

void print_1(std::ostream &os, const int i, const int j) {
    os << i << " " << j << std::endl;
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
    int v5 = 5;
    auto f5 = [v5]() mutable -> int { return ++v5; };
    std::cout << f5() << std::endl;
    std::cout << f5() << std::endl;

    // 10.3.3
    // 10.20
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    print(svec) << std::endl;

    size_t count = std::count_if(svec.begin(), svec.end(), [](const std::string &s) -> bool {
        constexpr std::size_t sz = 4;
        return s.size() >= sz;
    });
    std::cout << count << " words of length 4 or longer" << std::endl;

    // 10.21
    std::cout << "-------------------------" << std::endl;
    int c = 4;
    auto f6 = [&c]() -> bool {
        if(c <= 0) {
           return false; 
        } else {
            --c;
            return true;
        }
    };
    while(true) {
        if(f6()) {
            std::cout << c << " ";
        } else {
            std::cout << "zero reached";
            break;
        }
    }
    std::cout << std::endl;

    // 参数绑定
    std::cout << "-------------------------" << std::endl;
    using namespace std::placeholders;
    auto f7 = std::bind(check_size_1, _1, 5);
    std::cout << std::boolalpha << f7("hello world") << std::endl;
    std::cout << std::boolalpha << f7("hi") << std::endl;

    // bind的参数
    std::cout << "-------------------------" << std::endl;
    auto f8 = std::bind(print_string, _2, _1, _3);
    std::string str = "hello";
    f8("world", str, "!");
    f8("!", str, "world");

    // bind重排参数顺序
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    print(svec) << std::endl;
    std::stable_sort(svec.begin(), svec.end(), std::bind(isShorter, _2, _1));
    print(svec) << std::endl;
    std::stable_sort(svec.begin(), svec.end(), isShorter);
    print(svec) << std::endl;

    // 绑定引用参数 ref cref
    std::cout << "-------------------------" << std::endl;
    auto f9 = std::bind(print_1, std::ref(std::cout), 21, 73);
    f9();

    // 10.3.4
    // 10.22
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    count = std::count_if(svec.begin(), svec.end(), check_size);
    std::cout << count << " words of length 4 or longer" << std::endl;

    // 10.24
    std::cout << "-------------------------" << std::endl;
    str = "hello !";
    std::vector<int> ivec{1, 2, 3, 6, 7, 8, 5, 0, 9, 4};
    auto f10 = std::bind(check_size_2, _1, std::ref(str));

    auto iter = std::find_if(ivec.begin(), ivec.end(), f10);
    std::cout << *iter << std::endl;

    // 10.25
    std::cout << "-------------------------" << std::endl;
    svec = std::vector<std::string>{
        "the", "quick", "red", "fox", "jumps",
        "over", "the", "slow", "red", "turtle"
    };
    biggies_3(svec, 5);

    return 0;
}