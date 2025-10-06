// 参数传递
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <iterator>
#include <iterator>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

using vec_i = vector<int>;
// 6.2.1
// 6.10
void swap_pointer(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

// 6.2.2
// 6.11
void reset(int &refer) {
    refer = 0;
}

// 6.12
void swap_refer(int &r1, int &r2) {
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
}

// 6.2.3
// 6.17
bool have_upper(const string &str) {
    for(auto &e : str) {
        if(isupper(e)) {
            return true;
        }
    }
    return false;
}

void all_to_lower(string &str) {
    for(auto &e : str) {
        if(isupper(e)) {
            e = tolower(e);
        }
    }
}

// 6.18
// bool compare(matrix &m1, matrix &m2);
// vec_i::iterator change_val(int val, vec_i::iterator);

// 6.2.4
// 6.21
int compare(int a, const int *const pb) {
    return (a >= *pb ?  a : *pb);
}

// 6.22
void swap_address(int * &p1, int * &p2) {
    int *tmp = p1;
    p1 = p2;
    p2 = tmp;
}

// 6.23
void print_1(int i, const int (&j)[2]) {
    cout << i << endl;
    for(auto e : j) {
        cout << e << ' ';
    }
    cout << endl;
}

void print_2(int &i, const int j[], size_t sz) {
    cout << i << endl;
    for(size_t k = 0; k != sz; ++k) {
        cout << j[k] << ' ';
    }
    cout << endl;
}

void print_3(int i, const int *begin, const int *end) {
    cout << i << endl;
    for(; begin != end; ++begin) {
        cout << *begin << ' ';
    }
    cout << endl;
}

// 6.2.6
// 6.27
int add(initializer_list<int> val_list) {
    cout << val_list.size() << ": ";
    int sum = 0;
    for(auto it = val_list.begin(); it != val_list.end(); ++it) {
        sum += *it;
    }
    return sum;
}

void error_msg(int val, initializer_list<string> il) {
    cout << val << ": ";
    for(const auto &elem : il) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {

    // 传值参数
    int a = 1, b = 666;
    cout << "a = " << a << "    b = " << b << endl;
    swap_pointer(&a, &b);
    cout << "a = " << a << "  b = " << b << endl << endl;

    // 传引用参数
    cout << "a = " << a << endl;
    reset(a);
    cout << "a = " << a << endl << endl;

    cout << "a = " << a << "  b = " << b << endl;
    swap_refer(a, b);
    cout << "a = " << a << "  b = " << b << endl << endl;

    // const形参和实参
    string s1("hello World!");
    string s2("hi");
    cout << std::boolalpha << have_upper(s1) << "  " << have_upper(s2) << endl;

    string s3("HELLO, woRLD!");
    all_to_lower(s3);
    cout << s3 << endl << endl;

    // 数组形参
    a = 12, b = 666;
    int *pb = &b;
    cout << compare(a, pb) << endl;

    int *pa = &a;
    cout << "pa -> " << *pa << "   pb -> " << *pb << endl;
    swap_address(pa, pb);
    cout << "pa -> " << *pa << "  pb -> " << *pb << endl;

    int i = 0, j[2] = {0, 1};
    print_1(i, j);
    print_2(i, j, sizeof(j) / sizeof(j[0]));
    print_3(i, std::begin(j), std::end(j));

    // main: 处理命令行选项
    string str = std::to_string(argc) + " ";
    string s;
    for(int i = 0; i != argc; ++i) {
        str += argv[i];
        s += string(argv[i]) + " ";
    }
    cout << str << endl;
    cout << s << endl;

    // 含有可变形参的函数
    cout << add({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << endl;

    return 0;    
}