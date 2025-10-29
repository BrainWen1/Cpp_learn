// 动态内存与智能指针
#include <iostream>
#include <memory>

int main(void) {
    // shared_ptr
    std::shared_ptr<int> sp1(new int(42));
    std::shared_ptr<int> sp2 = sp1; // 共享所有权
    std::cout << "sp1: " << *sp1 << ", sp2: " << *sp2 << std::endl;
    std::cout << "Use count: " << sp1.use_count() << std::endl;
    std::cout << "Is unique: " << std::boolalpha << sp1.unique() << std::endl;

    // make_shared
    auto sp3 = std::make_shared<int>(100);
    std::cout << "sp3: " << *sp3 << std::endl;
    std::shared_ptr<int> sp4(sp3);
    std::cout << "Use count of sp3: " << sp3.use_count() << std::endl;

    sp3 = sp1; // sp3现在指向sp1所指对象，左侧对象引用计数减1，右侧对象引用计数加1
    std::cout << "After assignment, sp3: " << *sp3 << std::endl;
    std::cout << "Use count of sp1: " << sp1.use_count() << std::endl;
    std::cout << "Use count of sp4: " << sp4.use_count() << std::endl;

    swap(sp1, sp4); // 交换智能指针
    std::cout << "After swap, sp1: " << *sp1 << ", sp4: " << *sp4 << std::endl;
    std::cout << "Use count of sp1: " << sp1.use_count() << std::endl;
    std::cout << "Use count of sp4: " << sp4.use_count() << std::endl;

    auto p4 = sp4.get(); // 获取原始指针，但不影响引用计数
    std::cout << "Raw pointer from sp4: " << *p4 << std::endl;
    // delete p4; // 手动释放原始指针，注意这会导致悬空指针问题, 不要将get返回的指针delete

    sp4.reset(); // 释放sp4所指对象的所有权
    std::cout << "After reset, use count of sp4: " << sp4.use_count() << std::endl;
    std::cout << "sp4 is " << (sp4 ? "not null" : "null") << std::endl;
    std::cout << "Use count of sp2: " << sp2.use_count() << std::endl; // 2

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Use count of sp1: " << sp1.use_count() << std::endl; // 1
    sp1.reset(); // 释放sp1所指对象的所有权, 引用计数减1，所指内存被释放

    std::cout << "After reset, use count of sp1: " << sp1.use_count() << std::endl;
    std::cout << "sp1 is " << (sp1 ? "not null" : "null") << std::endl;

    return 0;
}