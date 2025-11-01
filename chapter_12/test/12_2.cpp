// 动态数组
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>

int main(void) {
    // new []
    int *arr = new int[10];
    delete[] arr;

    typedef int arrT[10];
    int *arr2 = new arrT;
    delete[] arr2;

    using arrTT = int[10];
    int *arr3 = new arrTT;
    delete[] arr3;

    // 初始化
    int *arr4 = new int[3](); // 值初始化
    int *arr5 = new int[3]{1, 2, 3}; // 列表初始化

    for(int i = 0; i < 3; ++i) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 3; ++i) {
        std::cout << arr5[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr4;
    delete[] arr5;

    // 智能指针和动态数组
    std::unique_ptr<int[]> arr6(new int[3]{4, 0, 6});
    for(int i = 0; i < 3; ++i) {
        std::cout << arr6[i] << " ";
    }
    std::cout << std::endl;
    arr6.release(); // 自动调用 delete[]

    std::shared_ptr<int> arr7(new int[3]{7, 8, 9}, [](int *p) { delete[] p; });
    for(int i = 0; i < 3; ++i) {
        std::cout << arr7.get()[i] << " ";
    }
    std::cout << std::endl;

    // 12.2.1
    // 12.23
    const char *arr8 = "hello ";
    const char *arr9 = "world!";

    char *arr10 = new char[std::strlen(arr8) + std::strlen(arr9) + 1];
    std::strcpy(arr10, arr8);
    std::strcat(arr10, arr9);

    std::cout << arr10 << std::endl;

    delete[] arr10;

    std::string arr11 = "hello ";
    std::string arr12 = "world!";
    std::string arr13 = arr11 + arr12;

    std::cout << arr13 << std::endl;

    // 12.24
    char ch = 0;
    char *arr14 = new char[100];
    while (std::cin >> ch && ch != 'q') {
        arr14[strlen(arr14)] = ch;
    }

    for(size_t i = 0; i < strlen(arr14); ++i) {
        std::cout << arr14[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr14;

    // allocator类
    std::allocator<int> ialloc;
    int *p1 = ialloc.allocate(5);

    for(size_t i = 0; i != 5; ++i) {
        ialloc.construct(p1 + i, i);
    }

    for(size_t i = 0; i != 5; ++i) {
        std::cout << p1[i] << " ";
    }
    std::cout << std::endl;

    for(size_t i = 0; i != 5; ++i) {
        ialloc.destroy(p1 + i);
    }
    ialloc.deallocate(p1, 5);

    // uninitialized memory
    int arr15[5] = {1, 2, 3, 4, 5};
    int *p2 = ialloc.allocate(10);

    auto q1 = std::uninitialized_copy(arr15, arr15 + 5, p2);
    std::uninitialized_fill(q1, q1 + 5, 666);

    for(size_t i = 0; i != 10; ++i) {
        std::cout << p2[i] << " ";
    }
    std::cout << std::endl;

    for(size_t i = 0; i != 10; ++i) {
        ialloc.destroy(p2 + i);
    }
    ialloc.deallocate(p2, 10);

    // 12.2.2
    // 12.26
    std::allocator<std::string> alloc;
    int n = 10;
    std::string *const p = alloc.allocate(n);
    std::string str;
    std::string *q = p;
    while (std::cin >> str && str != "q") {
        alloc.construct(q++, str);
    }
    const size_t size = q - p;

    // 使用数组
    for (size_t i = 0; i < size; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    q = p;
    for (size_t i = 0; i < size; ++i) {
        alloc.destroy(q + i);
    }
    alloc.deallocate(p, n);

    return 0;
}