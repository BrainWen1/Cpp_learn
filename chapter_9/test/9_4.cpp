// vector对象是如何增长的
#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ivec;

    std::cout << "size: " << ivec.size() << "    capacity: " << ivec.capacity() << std::endl; // 0 0

    for(decltype(ivec.size()) ix = 0; ix != 24; ++ix) {
        ivec.push_back(ix);
    }
    std::cout << "size: " << ivec.size() << "   capacity: " << ivec.capacity() << std::endl; // 24 32

    ivec.reserve(50);
    for(size_t ix = 24; ix != 50; ++ix) {
        ivec.push_back(ix);
    }
    std::cout << "size: " << ivec.size() << "   capacity: " << ivec.capacity() << std::endl; // 50 50

    ivec.push_back(50);
    std::cout << "size: " << ivec.size() << "   capacity: " << ivec.capacity() << std::endl; // 51 100

    return 0;
}