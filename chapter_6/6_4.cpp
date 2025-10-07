// 函数重载
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void func(int) {}
void func(int*) {}
void func(int &) {}

// 顶层const被忽略
// void func(const int) {}
// void func(int *const) {}

// 底层const被保留
void func(const int*) {}
void func(const int&) {}

// const_cast
const string &shorterString(const string &s1, const string &s2) {
    return s1.size() < s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2) {
    return (const_cast<string&> (shorterString(const_cast<const string&> (s1), const_cast<const string&> (s2))));
}

// 6.4
// 6.39
int calc(int, int) { return 0; }
// int calc(const int, const int) { return 0; }

int get() { return 0; }
// double get() { return 0; }

int *reset(int *) { return nullptr; }
double *reset(double *) { return nullptr; }

int main(void) {

    string s1("hello"), s2("hiya");
    auto &rstr = shorterString(s1, s2);

    cout << rstr << endl;
    cout << &rstr << " " << &s2 << endl;

    return 0;
}