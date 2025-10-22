// 泛型算法概述
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

int main(void) {
    // 10.1
    // 10.1
    std::vector<int> ivec = {1, -1, 0, 2, 1, 9, 11, 1, 178, 1};
    
    int num = 1;
    std::cout << num << " occurs " << std::count(ivec.begin(), ivec.end(), num) << " times." << std::endl;

    // 10.2
    std::list<std::string> ls{"hello", "hi", "hiya", "hi", "niko", "hi"};

    std::string str = "hi";
    std::cout << str << " occurs " << std::count(ls.begin(), ls.end(), str) << " times." << std::endl;

    return 0;
}