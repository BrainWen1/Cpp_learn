// 返回类型和 return 语句
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

char &get_val(string& str, string::size_type index) {
    return str[index];
}

// 6.3.2
// 6.30
bool str_subrange(const string &s1, const string &s2) {
    if(s1.size() == s2.size()) {
        return s1 == s2;
    }

    auto sz = (s1.size() < s2.size() ? s1.size() : s2.size());

    for(decltype(sz) i = 0; i != sz; ++i) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

// 6.32
int &get(int *array, int index) {
    return array[index];
}

// 6.33
void recur(vector<int> &ivec, vector<int>::size_type count) {
    if(count > 1) {
        recur(ivec, count - 1);
    }
    
    cout << ivec[count - 1] << ' ';
    return;
}

// 6.3.3
// 6.36
string (&func_0(int val)) [10] {
    static string str_arr_0[10] = {"111", "666"};
    cout << "func_0: " << val << endl;

    return str_arr_0;
}

using arrS = string[10];
arrS &func_1(int val) {
    static string str_arr_1[10] = {"777", "888"};
    cout << "func_1: " << val << endl;

    return str_arr_1;
}

auto func_2(int val) -> string(&)[10] {
    static string str_arr_2[10] = {"999", "000"};
    cout << "func_2: " << val << endl;

    return str_arr_2;
}

string str_arr_3[10] = {"333", "222"};
decltype(str_arr_3) &func_3(int val) {
    cout << "func_3: " << val << endl;

    return str_arr_3;
}

// 6.38
int  odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) &arrPtr(int i) {
    return (i % 2) ? odd : even;
}

int main(void) {

    // 引用返回左值
    string s("a sentence");
    cout << s << endl;
    get_val(s, 0) = 'A'; // 函数返回非常量引用作为左值
    cout << s << endl;

    // 6.3.2
    int ia[10];
    for(int i = 0; i != 10; ++i) {
        get(ia, i) = i;
    }
    for(auto &memb : ia) {
        cout << memb << ' ';
    }
    cout << endl;

    vector<int> ivec{1, 3, 5, 7, 9, 11};
    recur(ivec, ivec.size());
    cout << endl;

    // 6.3.3
    cout << func_0(9)[1] << endl;
    cout << func_1(8)[1] << endl;
    cout << func_2(7)[1] << endl;
    cout << func_3(6)[1] << endl;

    return EXIT_SUCCESS;
}