// 特殊用途语言特性
#define NDEBUG

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(size_t width, size_t height, char ch) {
    for(size_t i = 0; i != height; ++i) {
        for(size_t j = 0; j != width; ++j) {
            cout << ch;
        }
        cout << '\n';
    }
    cout << endl;
}

void print(size_t = 5, size_t = 5, char = '#');

// 6.5.1
// 6.42
inline string make_plural(size_t ctr, const string &word, const string &ending) {
    return (ctr > 1) ? word + ending : word;
}

string make_plural(size_t, const string &, const string & = "s");

// 6.5.2
// 6.44
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

constexpr int new_sz() {
    return 42;
}

void info(const int ia[], size_t sz) {
    assert(ia);

    #ifndef NDEBUG
        cout << __func__ << ": " << endl << "\t";
        cout << __DATE__ << "\n\t" << __TIME__ << "\n\t"
            << __FILE__ << "\n\t" << __LINE__ << "\n\t"
            << "array size is -> " << sz << endl;
    #endif
}

// 6.5.3
// 6.47
void recur(vector<int> &ivec, vector<int>::size_type count) {
    #ifndef NDEBUG
        cout << __func__ << ": vector size is -> " << ivec.size() << endl;
    #endif

    if(count > 1) {
        recur(ivec, count - 1);
    }
    
    cout << ivec[count - 1] << ' ';
    return;
}

int main(void) {

    // 默认实参
    print();
    print(2);
    print(3, 4);
    print(2, 3, '*');
    // print( , ,'?'); // error: 不允许省略前侧的实参
    print('?'); // '?' 的ASCII码值(63)作为数值传给第一个形参
    
    // 6.5.1
    // 6.42
    string s1("success"), s2("failure");
    cout << make_plural(1, s1) << " " << make_plural(2, s1, "es") << "\n"
        << make_plural(1, s2) << " " << make_plural(2, s2) << endl;

    // 内联函数和 constexpr 函数
    string s3("hello");
    cout << std::boolalpha << isShorter(s1, s3) << " " << isShorter(s3, s2)
        << " " << isShorter(s1, s2) << endl;

    constexpr int foo = new_sz();
    cout << foo << endl;

    // 调试帮助
    int ia[] = {1, 2, 3};

    assert(ia);
    info(ia, sizeof(ia) / sizeof(ia[0]));

    // 6.5.3
    // 6.47
    vector<int> ivec{11, 66, 56, 23, 990};
    recur(ivec, ivec.size());
    cout << endl;

    assert(false);
    cout << "No assert." << endl;
    
    return 0;
}