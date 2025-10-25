// 特定容器算法
#include <iostream>
#include <list>
#include <forward_list>

void print(std::list<int> &il) {
    for (const auto &e : il) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void elimDups(std::list<int> &il) {
    il.sort();        // 先排序
    il.unique();     // 再删除相邻重复元素
}

int main(void) {
    // merge
    std::list<int> il1 = {1, 3, 15, 40, 78};
    std::list<int> il2 = {10, 20, 30, 52, 66};

    il1.merge(il2);  // 合并两个有序链表
    print(il1);
    std::cout << il2.size() << std::endl;  // il2 已经为空

    // remove
    std::list<int> il3 = {1, 2, 3, 4, 5, 3, 3, 6};
    il3.remove(3);  // 删除所有值为3的元素
    print(il3);

    // remove_if
    std::list<int> il4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    il4.remove_if([](int &a) { return a % 2 == 0; });  // 删除所有偶数元素
    print(il4);

    // reverse
    std::cout << "---------------------" << std::endl;
    std::cout << "il1: " << std::endl;
    print(il1);
    il1.reverse();  // 反转链表
    std::cout << "reversed il1: " << std::endl;
    print(il1);

    // sort
    std::cout << "---------------------" << std::endl;
    std::list<int> il5 = {3, 5, 1, 4, 2, 8, 7, 6};
    il5.sort();  // 默认升序排序
    print(il5);
    il5.sort([](int a, int b) { return a > b; });  // 降序排序
    print(il5);

    // unique
    std::cout << "---------------------" << std::endl;
    std::list<int> il6 = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5};
    il6.unique();  // 删除相邻重复元素
    print(il6);
    std::list<int> il7 = {1, 2, 2, 3, 4, 4, 5, 5, 6};
    il7.unique([](int a, int b) { return (a + b) % 2 == 0; });  // 删除相邻元素和为偶数的元素
    print(il7);

    // splice
    std::cout << "---------------------" << std::endl;
    std::list<int> il8 = {1, 2, 3};
    std::list<int> il9 = {4, 5, 6};
    il8.splice(il8.end(), il9);  // 将il9的所有元素插入到il8的开头
    print(il8);
    std::list<int> il10 = {7, 8, 9};
    auto it = il10.begin();
    il8.splice(il8.begin(), il10, ++it);  // 将il10的第二个元素插入到il8的开头
    print(il8);
    std::list<int> il11 = {10, 11, 12, 13};
    auto it1 = il11.begin();
    auto it2 = il11.end();
    ++it1;  // 指向11
    --it2;  // 指向13
    il8.splice(il8.end(), il11, it1, it2);  // 将il11的[11,13)插入到il8的末尾
    print(il8);

    // 10.6
    // 10.42
    std::cout << "---------------------" << std::endl;
    std::list<int> il12 = {5, 2, 9, 1, 5, 6, 2, 9, 3, 5};
    elimDups(il12);
    print(il12);

    return 0;
}