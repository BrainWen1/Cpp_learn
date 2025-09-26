// 标准库类型vector
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::vector; // vector是一个类模板
using std::string;

void print(vector<int> &ivec) {
    auto sz = ivec.size();
    cout << sz << endl;

    for(auto i : ivec) {
        cout << i << ' ';
    }
    cout << endl;
}

void print(vector<string> &svec) {
    auto sz = svec.size();
    cout << sz << endl;

    for(auto i : svec) {
        cout << i << ' ';
    }
    cout << endl;
}

int main(void) {
    
    // 定义和初始化vector对象
    vector<int> v1;
    vector<int> v2(5, 666);
    vector<int> v3(v2);
    vector<int> v4 = v2;
    vector<int> v5(5); // 值初始化
    vector<int> v6{1, 2, 3, 4}; // 列表初始化
    vector<int> v7 = {2, 3, 4, 5};

    // 向vector对象中添加元素
    for(int i = 1; i != 101; ++i) {
        v1.push_back(i);
    }
    cout << "Size of v1 = " << v1.size() << endl;

    // 3.3.2
    // 3.14
    vector<int> ivec;
    int n = 0, num = 0;

    cout << "How many: ";
    cin >> n;

    while(n--) {
        cin >> num;
        ivec.push_back(num);
    }

    // 3.15
    vector<string> svec;
    string str;

    cout << "How many: ";
    cin >> n;

    while(n--) {
        cin >> str;
        svec.push_back(str);
    }

    // 其他vector操作
    cout << "Size of ivec = " << ivec.size() << endl;
    ivec = {};
    cout << "Size of ivec = " << ivec.size() << endl;

    vector<int>::size_type sz = ivec.size();

    if(!ivec.empty()) {
        for(auto i : ivec) {
            cout << i << ' ';
        }
        cout << endl;
    }

    // 3.3.3
    // 3.16
    vector<int> v8;
    vector<int> v9(10);
    vector<int> v10(10, 42);
    vector<int> v11{10};
    vector<int> v12{10, 42};
    vector<string> v13{10};
    vector<string> v14{10, "hi"};

    print(v8); print(v9); print(v10); print(v11); 
    print(v12); print(v13); print(v14);

    // 3.17
    svec = {};
    cout << "How many strings: ";
    cin >> n;
    while(n-- && cin >> str) {
        svec.push_back(str);
    }

    for(auto &e: svec) {
        for(auto &ch: e) {
            if(islower(ch)) {
                ch = toupper(ch);
            }
        }
    }

    for(auto e: svec) {
        cout << e << endl;
    }

    // 3.20
    ivec = {};
    cout << "How many integers: ";
    cin >> n;
    for(int i = 0; i != n; ++i) {
        cin >> num;
        ivec.push_back(num);
    }

    for(vector<int>::size_type i = 0; i != ivec.size() - 1; ++i) {
        cout << ivec[i] + ivec[i + 1] << ' ';
    }
    cout << endl;

    if(n % 2 == 1) {
        for(vector<int>::size_type i = 0; i != ((ivec.size() / 2) + 1); ++i) {
            cout << ivec[i] + ivec[ivec.size() - 1 - i] << ' ';
        }
    } else {
        for(vector<int>::size_type i = 0; i != (ivec.size() / 2); ++i) {
            cout << ivec[i] + ivec[ivec.size() - 1 - i] << ' ';
        }
    }
    cout << endl;

    return 0;
}