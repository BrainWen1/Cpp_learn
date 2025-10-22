#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void print(const std::vector<int> &ivec) {
    for(const auto &i : ivec) {
        std::cout << i << " ";
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
    

    return 0;
}