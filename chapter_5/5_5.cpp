// 跳转语句
#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int get_size() {
    int sz = 0;
    cout << "Enter the size: ";
    cin >> sz;

    return sz;
}

int main(void) {
    
    // 5.5.1
    // 5.20
    string prev, curr;
    bool flag = true;
    if(cin >> prev) {
        while(cin >> curr) {
            if(curr == prev) {
                flag = false;
                break;
            }
            prev = curr;
        }

        if(flag) {
            cout << "None" << endl;
        } else {
            cout << curr << endl;
        }
    }

    // 5.5.2
    // 5.21
    flag = true;
    if(cin >> prev) {
        while(cin >> curr) {
            if(curr == prev && isupper(curr[0])) {
                flag = false;
                break;
            }
            prev = curr;
        }

        if(flag) {
            cout << "None" << endl;
        } else {
            cout << curr << endl;
        }
    }

    // 5.5.3
    // 5.22
    int sz = 0;
    while((sz = get_size()) <= 0) ;

    cout << "sz: " << sz << endl;

    return 0;
}