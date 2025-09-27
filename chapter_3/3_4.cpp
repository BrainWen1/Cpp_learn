// 迭代器介绍
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <cctype>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(vector<int> &ivec) {
    auto sz = ivec.size();
    cout << sz << endl;

    for(auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

void print(vector<string> &svec) {
    auto sz = svec.size();
    cout << sz << endl;

    for(auto it = svec.cbegin(); it != svec.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main(void) {

    // 使用迭代器
    string str{"some words"};
    if(str.begin() != str.end()) {
        *str.begin() = toupper(*str.begin());
    }
    cout << str << endl;

    // 移动迭代器
    str = {"some thing"};
    for(auto it = str.begin(); it != str.end() && *it != ' '; ++it) {
        *it = toupper(*it);
    }
    cout << str << endl;

    // 迭代器类型
    string s{"hello, world!"};
    const string cs{"CONST hello, world!"};
    string::iterator sit = s.begin();
    string::const_iterator sit_c = s.begin();
    string::const_iterator csit = cs.begin();

    vector<int> ivec{1, 2, 3};
    const vector<int> civec{9, 1, 0};
    vector<int>::iterator ivecit = ivec.begin();
    vector<int>::const_iterator ivecit_c = ivec.begin();
    vector<int>::const_iterator civecit = civec.begin();

    //
    vector<string> text{"Fuck", "you", "HHhHH", "", "NB"};
    for(auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) {
        cout << *it << endl;
    }

    // 3.4.1
    // 3.21
    vector<int> v8;
    vector<int> v9(10);
    vector<int> v10(10, 42);
    vector<int> v11{10};
    vector<int> v12{10, 42};
    vector<string> v13{10};
    vector<string> v14{10, "hi"};

    print(v8); print(v9); print(v10); print(v11); 
    print(v12); print(v13); print(v14);
    cout << endl;

    // 3.22
    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for(auto cit = it->begin(); cit != it->end(); ++cit) {
            *cit = toupper(*cit);
        }
        cout << *it << endl;
    }

    // 3.23
    ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it <<= 1;
        cout << *it << ' ';
    }
    cout << endl;
    
    // 迭代器运算
    vector<int>::iterator it = ivec.begin() + ivec.size() / 2; // 12
    cout << *(it + 4) << ' '; // 20
    cout << *(it - 2) << ' '; // 8
    cout << ivec.end() - ivec.begin() << ' '; // 10 -> difference_type
    cout << std::boolalpha << (ivec.end() > ivec.begin()) << endl; // true

    vector<int>::difference_type vecDiff_sz = ivec.begin() - ivec.end(); // ptrdiff_t
    string::difference_type strDiff_sz = s.end() - s.begin();

    cout << typeid(vecDiff_sz).name() << ' ' << typeid(strDiff_sz).name() << endl; // x x -> ptrdiff_t
    cout << vecDiff_sz << ' ' << strDiff_sz << endl << endl; // -10 13

    // 使用迭代器运算 -> 二分搜索
    ivec = {-2, 0, 1, 6, 8, 12, 88, 108, 520, 1024};
    auto left = ivec.cbegin(), right = ivec.cend();
    auto mid = left + (right - left) / 2;
    int sought = 0;
    cout << "sought = ";
    cin >> sought;

    while(mid != right && *mid != sought) {
        if(*mid < sought) {
            left = mid + 1;
        } else {
            right = mid;
        }
        
        mid = left + (right - left) / 2;
    }

    if(mid == right) {
        cout << "None" << endl;
    } else {
        cout << "Sought is the No." << (mid - ivec.cbegin() + 1) << endl;
    }

    // 3.4.2
    // 3.24
    ivec = {};
    int n = 0, num = 0;

    cout << "How many integers: ";
    cin >> n;

    cout << "Enter your integers: ";
    for(int i = 0; i != n; ++i) {
        cin >> num;
        ivec.push_back(num);
    }

    for(auto it = ivec.cbegin(); it != ivec.cend() - 1; ++it) { // 相邻
        cout << *it + *(it + 1) << ' ';
    }
    cout << endl;

    if(n % 2 == 1) { // 两端
        for(auto it = ivec.cbegin(); it != ivec.cbegin() + ivec.size() / 2 + 1; ++it) {
            cout << *it + *(ivec.cend() - (it - ivec.cbegin() + 1)) << ' ';
        }
    } else {
        for(auto it = ivec.cbegin(); it != ivec.cbegin() + ivec.size() / 2; ++it) {
            cout << *it + *(ivec.cend() - (it - ivec.cbegin() + 1)) << ' ';
        }
    }
    cout << endl;

    // 3.25
    vector<int> scores(11, 0);
    unsigned grade = 0;

    cout << "Enter your grades: ";
    while(cin >> grade) {
        auto it = scores.begin();
        ++(*(it + grade / 10));
    }

    for(auto it = scores.cbegin(); it != scores.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}