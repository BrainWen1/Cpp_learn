// 标准库类型vector
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector; // vector是一个类模板
using std::string;

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

    return 0;
}