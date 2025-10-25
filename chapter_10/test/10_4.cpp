// 再探迭代器
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <deque>
#include <fstream>
#include "chapter_10/Sales_data.h"

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

void print(std::vector<Sales_data> &vec) {
    for(const auto &mem : vec) {
        print(std::cout, mem) << std::endl;
    }
}

bool compareIsbn(const Sales_data &item1, const Sales_data &item2) {
    return item1.isbn() < item2.isbn();
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
    std::cout << "-------------------" << std::endl;
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
    std::cout << "-------------------" << std::endl;
    std::cout << "Please enter integers separated by spaces:" << std::endl;
    std::ifstream infile("../test/txt/10_4test.txt");
    std::istream_iterator<int> inf_it(infile), eof;

    ivec.clear();
    while(inf_it != eof) {
        ivec.push_back(*inf_it++);
    }
    std::cout << "You entered:" << std::endl;
    std::ostream_iterator<int> cout_it(std::cout, " ");
    std::copy(ivec.begin(), ivec.end(), cout_it);
    std::cout << std::endl;

    // 10.4.2
    // 10.29
    std::cout << "-------------------" << std::endl;
    infile.close();
    infile.open("../test/txt/10_4prac.txt");
    std::istream_iterator<std::string> str_it(infile), str_eof;
    svec.clear();
    while(str_it != str_eof) {
        svec.push_back(*str_it++);
    }
    infile.close();
    std::copy(svec.begin(), svec.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    // 10.30
    std::cout << "-------------------" << std::endl;
    std::istream_iterator<int> in_it(std::cin);
    ivec.clear();

    std::copy_n(in_it, 5, std::back_inserter(ivec));
    std::sort(ivec.begin(),ivec.end());

    std::cout << "Sorted integers:" << std::endl;
    std::copy(ivec.begin(), ivec.end(), cout_it);
    std::cout << std::endl;

    // 10.31
    std::cout << "-------------------" << std::endl;
    ivec.clear();

    std::copy_n(std::istream_iterator<int>(std::cin), 6, std::back_inserter(ivec));
    print(ivec);
    std::sort(ivec.begin(), ivec.end());
    print(ivec);

    std::unique_copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // 10.32
    std::cout << "-------------------" << std::endl;
    std::vector<Sales_data> sales_vec;
    infile.open("../test/txt/10_4books.txt");

    Sales_data total;
    if(read(infile, total)) {
        Sales_data trans;
        while(read(infile, trans)) {
            if(total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                sales_vec.push_back(total);
                total = trans;
            }
        }
        sales_vec.push_back(total);
    } else {
        std::cerr << "No data?!" << std::endl;
    }

    infile.close();

    std::sort(sales_vec.begin(), sales_vec.end(), compareIsbn);
    print(sales_vec);

    // 10.33
    std::cout << "-------------------" << std::endl;
    infile.open("../test/txt/10_4test.txt");
    std::ofstream odd_file("../test/txt/10_4_odd.txt"), even_file("../test/txt/10_4_even.txt");
    
    int num = 0;
    std::istream_iterator<int> it(infile);
    std::ostream_iterator<int> odd_it(odd_file, " "), even_it(even_file, " ");
    while(it != eof) {
        if(*it % 2 == 1 || *it % 2 == -1) {
            odd_it = *it;
        } else {
            even_it = *it;
        }
        ++it;
    }

    // 反向迭代器
    std::cout << "-------------------" << std::endl;
    ivec = {1, 2, 3, 4, 5};

    for(auto it = ivec.crbegin(); it != ivec.crend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for(auto it = ivec.crend() - 1; it != ivec.crbegin() - 1; --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 10.4.3
    // 10.35
    std::cout << "-------------------" << std::endl;

    for(auto it = ivec.cend() - 1; it != ivec.cbegin() - 1; --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 10.36
    std::cout << "-------------------" << std::endl;

    il.clear();
    il = {0, 1, 2, 3, 0, 9, 8, 2, 0, 6, 2, 3};

    auto rit = std::find_if(il.rbegin(), il.rend(), [](const auto &i) -> bool {
        return i == 0;
    });

    auto iter = rit.base();
    std::cout << *it << " " << *(iter) << std::endl;

    // 10.37
    std::cout << "-------------------" << std::endl;

    ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    il.clear();

    std::copy(ivec.rbegin() + 2, ivec.rend() - 3, std::back_inserter(il));

    std::copy(il.begin(), il.end(), std::ostream_iterator<int> (std::cout, " "));

    return 0;
}