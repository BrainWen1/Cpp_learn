// 多维数组
#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 多维数组的下标引用
    int ia[2][3] = {1, 2, 3, 4, 5};
    int (&row)[3] = ia[1];
    for(auto e : row) {
        cout << e << " ";
    }
    cout << endl;

    // 使用范围for处理多维数组
    for(auto &r : ia) {
        for(auto &c : r) {
            ++c;
        }
    }

    for(auto &r : ia) { // 使用引用来显式阻止数组名被转换为指针
        for(auto c : r) {
            cout << c << ' ';
        }
        cout << endl;
    }

    // 类型别名简化多维数组的指针
    using int_array = int[4];
    typedef char char_array[4]; // (&, *, [])这些用于构成复合类型的符号应该与标识符相结合

    int_array a = {1, 2, 3, 4};
    char_array b = {'h', 'i', 'y', 'a'};

    for(auto e : a) {
        cout << e << ' ';
    }
    cout << endl;
    for(auto e : b) {
        cout << e << ' ';
    }
    cout << endl;

    cout << "---------------------------------------" << endl;

    // 3.6
    // 3.43
    int num = 0;
    int arr[3][4] = {0};
    for(int i = 0; i != 3; ++i) {
        for(int j = 0; j != 4; ++j) {
            arr[i][j] = num;
            ++num;
        }
    }

    for(int (&m)[4] : arr) { // 范围for
        for(int n : m) {
            cout << n << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i != sizeof(arr) / sizeof(arr[0]); ++i) { // 下标运算符
        for(int j = 0; j != sizeof(arr[0]) / sizeof(arr[0][0]); ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    
    for(int (*pa)[4] = arr; pa != std::end(arr); ++pa) { // 指针
        for(int *pi = *pa; pi != std::end(*pa); ++pi) {
            cout << *pi << ' ';
        }
        cout << endl;
    }
    cout << endl;

    cout << "---------------------------------------" << endl;

    // 3.44
    using int_array = int[4];

    for(int_array &m : arr) { // 范围for
        for(int n : m) {
            cout << n << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i != sizeof(arr) / sizeof(arr[0]); ++i) { // 下标运算符
        for(int j = 0; j != sizeof(arr[0]) / sizeof(arr[0][0]); ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    using int_ptr = int *;

    for(int_array *pa = arr; pa != std::end(arr); ++pa) { // 指针
        for(int_ptr pi = *pa; pi != std::end(*pa); ++pi) {
            cout << *pi << ' ';
        }
        cout << endl;
    }
    cout << endl;

    cout << "---------------------------------------" << endl;

    // 3.45
    for(auto &m : arr) { // 范围for
        for(auto n : m) {
            cout << n << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(auto i = 0; i != sizeof(arr) / sizeof(arr[0]); ++i) { // 下标运算符
        for(auto j = 0; j != sizeof(arr[0]) / sizeof(arr[0][0]); ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    
    for(auto pa = arr; pa != std::end(arr); ++pa) { // 指针
        for(auto pi = *pa; pi != std::end(*pa); ++pi) {
            cout << *pi << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}