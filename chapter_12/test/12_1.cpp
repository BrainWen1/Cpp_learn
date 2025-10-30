// 动态内存与智能指针
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <new> // std::nothrow
#include <fstream>

std::vector<int> *ReturnVector() {
    std::vector<int> *p = new std::vector<int>();
    return p;
}

std::vector<int> *FillVector() {
    std::vector<int> *p = ReturnVector();
    if(p) {
        std::ifstream in("../test/txt/12_1.txt");
        if(in) {
            int val;
            while(in >> val) {
                p->push_back(val);
            }
            in.close();
        }
    }
    return p;
}

void PrintVector() {
    const std::vector<int> *p = FillVector();
    if(p) {
        for(const auto &elem : *p) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    delete p;
}

std::shared_ptr<std::vector<int>> CreateVector() {
    std::shared_ptr<std::vector<int>> p = std::make_shared<std::vector<int>>();
    return p;
}

std::shared_ptr<std::vector<int>> FillSharedVector() {
    std::shared_ptr<std::vector<int>> p = CreateVector();
    if(p) {
        std::ifstream in("../test/txt/12_1.txt");
        if(in) {
            int val;
            while(in >> val) {
                p->push_back(val);
            }
            in.close();
        }
    }
    return p;
}

void PrintSharedVector() {
    std::shared_ptr<std::vector<int>> p = FillSharedVector();
    if(p) {
        for(const auto &elem : *p) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// 12.1.4
struct destination {
    std::string ip;
    int port = 0;
};

struct connection {
    destination *dest = nullptr;
};

connection connect(destination* pDest) {
    return connection();
}

void disconnect(connection c) {
    // 断开连接的实现
    c.dest = nullptr;
}

// 12.14
void end_connection(connection *pConn) {
    disconnect(*pConn);
}

void f(destination &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection);
    // 使用连接c的代码
}

// 12.15
void f1(destination &d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *pc) {
        disconnect(*pc);
    });
}

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

    // 直接管理内存
    std::cout << "-------------------------------" << std::endl;
    int *pi = new int(256);
    std::string *ps = new std::string(5, 'c');
    std::cout << "pi: " << *pi << ", ps: " << *ps << std::endl;
    delete pi;
    delete ps;

    std::vector<int> *pv = new std::vector<int>{1, 2, 3, 4, 5};
    for (const auto &elem : *pv) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    delete pv;

    // 值初始化
    int *pi2 = new int(); // 值初始化为0
    std::cout << "Value initialized int: " << *pi2 << std::endl;
    delete pi2;

    // 定位new
    std::cout << "-------------------------------" << std::endl;
    int *p1 = new int(42); // 如果分配失败，抛出异常
    int *p2 = new (std::nothrow) int(84); // 如果分配失败，返回空指针

    // 12.1.2
    // 12.6
    PrintVector();
    PrintSharedVector();

    // shared_ptr 和 new
    std::cout << "-------------------------------" << std::endl;
    // std::shared_ptr<int> sp5 = new int(512); // 错误，不允许直接用new初始化shared_ptr
    std::shared_ptr<int> sp5(new int(512)); // 正确，但不推荐
    // sp5 = new int(1024); // 错误，不能将原始指针赋值给shared_ptr
    sp5.reset(new int(2048)); // 正确，但不推荐
    std::cout << "sp5: " << *sp5 << std::endl;

    // 推荐使用make_shared
    std::shared_ptr<int> sp6 = std::make_shared<int>(4096);
    std::cout << "sp6: " << *sp6 << std::endl;
    sp6 = std::make_shared<int>(8192);
    std::cout << "sp6 after assignment: " << *sp6 << std::endl;

    // unique_ptr
    std::unique_ptr<int> up1(new int(42));
    std::cout << "up1: " << *up1 << std::endl;
    // std::unique_ptr<int> up2 = up1; // 错误，不能复制unique_ptr
    
    int *up2 = up1.release(); // 转移所有权
    std::cout << "After release, up1 is " << (up1 ? "not null" : "null") << std::endl;
    std::cout << "up2: " << *up2 << std::endl;
    delete up2; // 手动释放原始指针

    int *up3 = new int(84);
    up1.reset(up3); // 重新获得所有权
    std::cout << "After reset, up1: " << *up1 << std::endl;

    auto lam = []() {
        std::unique_ptr<int> up(new int(128));
        return up;
    };
    std::unique_ptr<int> up4 = lam();
    std::cout << "up4: " << *up4 << std::endl;

    // 12.1.5
    // 12.16
    // std::unique_ptr<int> up5 = up4;

    // weak_ptr
    std::cout << "-------------------------------" << std::endl;
    std::shared_ptr<int> spw1 = std::make_shared<int>(256);
    std::weak_ptr<int> wp1 = spw1; // weak_ptr 不影响引用计数
    std::cout << "Use count of spw1: " << spw1.use_count() << std::endl;
    if (auto spw2 = wp1.lock()) { // 尝试获取shared_ptr
        std::cout << "Locked value: " << *spw2 << std::endl;
    } else {
        std::cout << "wp1 is expired." << std::endl;
    }

    return 0;
}