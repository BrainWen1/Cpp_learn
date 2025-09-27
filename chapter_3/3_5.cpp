// 数组
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void) {

    // 定义和初始化内置数组
    constexpr unsigned sz = 10;
    int iarr_1[10] = {0};
    int iarr_2[sz] = {0};

    char carr_1[] = {'C', '+', '+'};
    char carr_2[] = "C++";
    cout << sizeof(carr_1) / sizeof(carr_1[0]) << " " << sizeof(carr_2) / sizeof(carr_2[0]) << endl;

    // 访问数组元素 -> 范围for 下标运算符
    for(auto e : carr_1) {
        cout << e;
    }
    cout << endl;

    for(int i = 0; i != sizeof(carr_1) / sizeof(carr_1[0]); ++i) {
        cout << carr_1[i];
    }
    cout << endl;

    // 3.5.2
    // 3.31
    for(int i = 0; i != sizeof(iarr_1) / sizeof(iarr_1[0]); ++i) {
        iarr_1[i] = i;
    }
    for(auto e : iarr_1) {
        cout << e << ' ';
    }
    cout << endl;

    // 3.32
    for(int i = 0; i != sizeof(iarr_1) / sizeof(iarr_1[0]); ++i) {
        iarr_2[i] = iarr_1[i];
    }
    for(auto e: iarr_2) {
        cout << e << ' ';
    }
    cout << endl;

    vector<int> ivec_1(10);
    vector<int> ivec_2(10);
    for(int i = 0; i != ivec_1.size(); ++i) {
        ivec_1[i] = i;
    }
    ivec_2 = ivec_1;

    for(auto e : ivec_1) {
        cout << e << ' ';
    }
    cout << endl;
    for(auto e : ivec_2) {
        cout << e << ' ';
    }
    cout << endl;

    // 指针和数组
    int *p1 = iarr_1;
    cout << *p1 << " " << p1 << endl;

    decltype(iarr_1) iarr_3{11, 22, 33, 4, 5, 6, 77}; // decltype返回数组
    for(auto e : iarr_3) {
        cout << e << ' ';
    }
    cout << endl << endl;

    // 标准库函数 begin 和 end -> <iterator>
    auto left = std::begin(iarr_1);
    auto right = std::end(iarr_1);
    for(auto it = left; it != right; ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // 3.5.3
    // 3.35
    int *p = iarr_1;
    for(int i = 0; i != sizeof(iarr_1) / sizeof(iarr_1[0]); ++i) {
        *(p + i) = 0;
    }
    for(auto e : iarr_1) {
        cout << e << ' ';
    }
    cout << endl;

    // 3.36
    int iarr_4[5]{1, 2, 3, 4, 5};
    int iarr_5[5]{1, 2, 3, 4, 5};
    int flag = 1;
    for(int i = 0; i != 5; ++i) {
        if(iarr_4[i] != iarr_5[i]) {
            cout << "Unequal" << endl;
            flag = 0;
            break;
        }
    }
    if(flag) {
        cout << "equal" << endl;
    }

    ivec_1 = {1, 2, 3, 4, 5};
    ivec_2 = {1, 2, 4, 0, 0};
    if(ivec_1 == ivec_2) {
        cout << "equal" << endl;
    } else {
        cout << "Unequal" << endl;
    }

    // C风格字符串
    // 3.5.4
    // 3.39
    string s1("hello");
    string s2("hiya");
    if(s1 > s2) {
        cout << "s1 > s2" << endl;
    } else if(s1 < s2) {
        cout << "s1 < s2" << endl;
    } else {
        cout << "s1 = s2" << endl;
    }

    const char cstr1[] = "world";
    const char cstr2[] = "word";
    int ret = strcmp(cstr1, cstr2);
    if(ret > 0) {
        cout << "cstr1 > cstr2" << endl;
    } else if(ret < 0) {
        cout << "cstr1 < cstr2" << endl;
    } else {
        cout << "cstr1 = cstr2" << endl;
    }

    // 3.40
    char cstr3[] = "Hello, ";
    char cstr4[] = "World!";
    char cstr5[100] = {0};

    strcpy(cstr5, cstr3);
    strcat(cstr5, cstr4);

    cout << cstr5 << endl;

    // 与旧代码的接口
    const char* pstr = s1.c_str(); // string的成员函数c_str
    cout << s1 << "  " << pstr << endl;

    int iarr[6] = {-2, -1, 0, 1, 2, 3};
    vector<int> ivec(std::begin(iarr), std::end(iarr)); // 用内置数组初始化vector对象
    for(auto e : ivec) {
        cout << e << ' ';
    }
    cout << endl;

    // 3.5.5
    // 3.41
    vector<int> ivec_3(std::begin(iarr), std::end(iarr)); // 用内置数组初始化vector对象
    for(auto e : ivec_3) {
        cout << e << ' ';
    }
    cout << endl;

    // 3.42
    vector<int> ivec_4{1, 2, 0, 5, 6, 11};
    for(int i = 0; i != ivec_4.size(); ++i) {
        iarr[i] = ivec_4[i];
    }
    for(auto e : iarr) {
        cout << e << ' ';
    }
    cout << endl;

    return 0;
}