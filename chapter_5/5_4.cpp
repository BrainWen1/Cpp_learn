// 迭代语句
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void) {

    // 5.4.1
    // 5.14
    string maxWord, curWord, prev;
    unsigned maxCnt = 1, curCnt = 1;

    if(cin >> maxWord) {
        prev = maxWord;
        while(cin >> curWord) {            
            if(curWord == prev) {
                ++curCnt;
                if(curCnt > maxCnt) {
                    maxCnt = curCnt;
                    maxWord = curWord;
                }
            } else {
                curCnt = 1;
                prev = curWord;
            }
        }
    }
    
    if(maxCnt > 1) {
        cout << maxWord << ": " << maxCnt << endl;
    } else {
        cout << "None" << endl;
    }

    // 5.4.2
    // 5.17
    vector<int> ivec_1{0, 1, 1, 2}, ivec_2{0, 1, 1, 2, 3, 5, 8};

    size_t sz1 = ivec_1.size(), sz2 = ivec_2.size();
    size_t minsz = (sz1 < sz2) ? (sz1) : (sz2);

    bool flag = true;
    for(size_t i = 0; i < minsz; ++i) {
        if(ivec_1[i] != ivec_2[i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "yes" << endl;
    } else {
        cout << "no"  << endl;
    }

    // 5.4.4
    // 5.19
    string s1, s2;
    do {
        cout << "Enter two strings: ";
        cin >> s1 >> s2;
        string str = (s1.size() < s2.size()) ? (s1) : (s2);
        cout << "The shorter one: " << str << endl;
    } while(cin); 

    return 0;
}