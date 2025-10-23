#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

void print(const std::vector<int> &ivec) {
    for(const auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print(const std::vector<std::string> &svec) {
    for(const auto &s : svec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    // 只读算法
    // accumulate
    std::vector<int> ivec(10);
    std::iota(ivec.begin(), ivec.end(), 1); // 赋值1-10
    int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::cout << "sum: " << sum << std::endl;

    // equal
    std::vector<int> ivec2(10);
    std::iota(ivec2.begin(), ivec2.end(), 1);

    if(std::equal(ivec.cbegin(), ivec.cend(), ivec2.cbegin())) {
        std::cout << "ivec equal ivec2" << std::endl;
    } else {
        std::cout << "ivec not equal ivec2" << std::endl;
    }

    std::vector<int> ivec3(10);
    std::iota(ivec3.begin(), ivec3.end(), 0);

    if(std::equal(ivec.cbegin(), ivec.cend(), ivec3.cbegin())) {
        std::cout << "ivec equal ivec3" << std::endl;
    } else {
        std::cout << "ivec not equal ivec3" << std::endl;
    }
    
    // 写容器元素的算法
    // fill
    print(ivec);
    std::fill(ivec.begin(), ivec.end(), 6);
    print(ivec);

    // fill_n
    std::fill_n(ivec.begin(), ivec.size() / 2, 3);
    print(ivec);

    // back_inserter
    auto it = std::back_inserter(ivec);
    *it = 10;
    print(ivec);
    std::fill_n(std::back_inserter(ivec), 5, 8);
    print(ivec);

    // 拷贝算法
    // copy
    std::cout << "-----------------" << std::endl;
    print(ivec2);
    print(ivec3);
    std::copy(ivec2.cbegin(), ivec2.cend(), ivec3.begin());
    print(ivec3);
    std::cout << "-----------------" << std::endl;

    std::vector<int> ivec4;
    std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(ivec4));
    print(ivec4);

    // replace
    std::cout << "-----------------" << std::endl;
    print(ivec4);
    std::replace(ivec4.begin(), ivec4.end(), 6, 9);
    print(ivec4);

    // replace_copy
    std::vector<int> ivec5;
    std::replace_copy(ivec4.cbegin(), ivec4.cend(), std::back_inserter(ivec5), 9, 7);
    print(ivec5);

    // 10.2.2
    // 10.6
    std::cout << "-----------------" << std::endl;
    std::vector<int> ivec6(10);
    std::iota(ivec6.begin(), ivec6.end(), 1);
    print(ivec6);

    std::fill_n(ivec6.begin(), ivec6.size(), 0);
    print(ivec6);

    // 重排容器元素的算法
    // 消除重复单词
    // sort + unique + erase
    std::cout << "-----------------" << std::endl;
    std::vector<std::string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    print(svec);
    std::cout << svec.size() << std::endl;
    
    std::sort(svec.begin(), svec.end());
    print(svec);
    std::cout << svec.size() << std::endl;

    auto end_unique = std::unique(svec.begin(), svec.end());
    print(svec);
    std::cout << svec.size() << std::endl;

    svec.erase(end_unique, svec.end());
    print(svec);
    std::cout << svec.size() << std::endl;

    return 0;
}