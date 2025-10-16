// 容器库概览
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

// 9.2.1
// 9.4
bool find_from_bool(std::vector<int>::iterator begin, std::vector<int>::iterator end, int sought) {
    for(; begin != end; ++begin) {
        if((*begin) == sought) {
            return true;
        }
    }
    return false;
}

// 9.5
std::vector<int>::iterator find_from_iter(std::vector<int>::iterator begin, std::vector<int>::iterator end, int sought) {
    for(; begin != end; ++begin) {
        if((*begin) == sought) {
            return begin;
        }
    }
    return end;
}

std::ostream &print(std::ostream &os, std::vector<int> &ivec) {
    for(const auto &mem : ivec) {
        os << mem << " ";
    }
    return os;
}

// 9.16
bool compare_ls_vec(std::list<int> &ls, std::vector<int> &vec) {
    if(ls.size() != vec.size()) {
        return false;
    }

    auto beg1 = ls.begin();
    auto beg2 = vec.begin();
    for(; beg1 != ls.end(); ++beg1, ++beg2) {
        if((*beg1) != (*beg2)) {
            return false;
        }
    }
    return true;
}

int main(void) {
    // 9.2
    // 9.2
    std::list<std::deque<int>> ldi;

    // 9.2.1
    // 9.4
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << std::boolalpha << find_from_bool(ivec.begin(), ivec.end(), 1) << " ";
    std::cout << std::boolalpha << find_from_bool(ivec.begin(), ivec.end(), 11) << " ";
    std::cout << std::boolalpha << find_from_bool(ivec.begin() + 2, ivec.end() - 2, 2) << " ";
    std::cout << std::boolalpha << find_from_bool(ivec.begin() + 2, ivec.end() - 2, 8) << std::endl;

    auto iter = find_from_iter(ivec.begin(), ivec.end(), 1);
    if(iter != ivec.end()) {
        std::cout << *iter << " ";
    } else {
        std::cout << "Not found" << " ";
    }

    iter = find_from_iter(ivec.begin(), ivec.end(), 11);
    if(iter != ivec.end()) {
        std::cout << *iter << " ";
    } else {
        std::cout << "Not found" << " ";
    }
    std::cout << std::endl;

    // 9.2.4
    // 9.11
    std::vector<int> vec1;
    std::vector<int> vec2(ivec);
    std::vector<int> vec3 = vec2;
    std::vector<int> vec4{1, 2};
    std::vector<int> vec5 = {3, 4};
    std::vector<int> vec6(ivec.begin(), ivec.begin() + 3);
    std::vector<int> vec7(5);
    std::vector<int> vec8(3, 6);

    print(std::cout, vec1) << std::endl; print(std::cout, vec2) << std::endl;
    print(std::cout, vec3) << std::endl; print(std::cout, vec4) << std::endl;
    print(std::cout, vec5) << std::endl; print(std::cout, vec6) << std::endl;
    print(std::cout, vec7) << std::endl; print(std::cout, vec8) << std::endl;

    // 9.2.7
    // 9.15
    if(vec1 == vec2) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }

    if(vec2 == vec3) {
        std::cout << "equal" << std::endl;
    } else {
        std::cout << "not equal" << std::endl;
    }
    
    // 9.16
    std::list<int> ls1{0, 1, 2};

    std::cout << std::boolalpha << compare_ls_vec(ls1, vec6) << std::endl;
    std::cout << std::boolalpha << compare_ls_vec(ls1, vec8) << std::endl;

    return 0;
}