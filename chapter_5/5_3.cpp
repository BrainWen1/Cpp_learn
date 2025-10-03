// 条件语句
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void) {

    // if语句
    // 悬垂else: else与离它最近的尚未匹配的if匹配
    if(false)
        if(false)
            ;
    else // warning: suggest explicit braces to avoid ambiguous 'else'
        ;

    // 5.3.1
    // 5.5
    const vector<string> scores{"F", "D", "C", "B", "A", "A++"};
    int grade = 0;
    string lettergrade;

    while(cin >> grade && grade) {
        if(grade < 60) {
            lettergrade = scores[0];
        } else {
            lettergrade = scores[(grade - 50) / 10];

            if(grade % 10 >= 8) {
                lettergrade += '+';
            } else if(grade % 10 <= 2 && grade != 100) {
                lettergrade += '-';
            }
        }
        cout << lettergrade << "  ";
    }
    cout << endl;

    // 5.6
    while(cin >> grade && grade) {
        lettergrade = (grade < 60) ? (scores[0]) : (scores[(grade - 50) / 10] + ((grade % 10 >= 8) ?
            ("+") : ((grade % 10 <= 2 && grade != 100) ? ("-") : (""))));

        cout << lettergrade << "  ";
    }
    cout << endl;

    // switch语句
    int day = 0;
    cout << "Today?" << " ";
    cin >> day;
    switch(day) {
        case 1: case 2: case 3: case 4: case 5:
            cout << "Have a nice workday!" << endl;
            break;
        case 6: case 7:
            cout << "Happy weekend!" << endl;
            break;
        default:
            cout << "Wrong input!" << endl;
            break; 
    }

    // switch内部的变量定义
    bool bl = false;
    switch(static_cast<int> (bl)) {
        case true:
            // string str;  // error: 控制传输跳过的实例化 -> string对象隐式构造初始化
            // int val = 0; // error: 同上 -> 显式初始化
            int val;
            break;
        case false:
            val = 666;
            cout << val << endl;
            break;
        default:
            cout << "Error!" << endl;
            break;
    }

    switch(static_cast<int> (bl)) {
        case true: {
            string str;
            int num = 111;
            break;
        }
        case false: {
            // cout << num << endl; // error: 未定义标识符，{}限定了作用域
            int num = 2233;
            cout << num << endl;
            break;
        }
        default: {
            cout << "Error!" << endl;
            break;
        }
    }

    // 5.3.2
    // 5.9
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch = 0;
    while(cin >> ch) {
        if(ch == 'a') {
            ++aCnt;
        } else if(ch == 'e') {
            ++eCnt;
        } else if(ch == 'i') {
            ++iCnt;
        } else if(ch == 'o') {
            ++oCnt;
        } else if(ch == 'u') {
            ++uCnt;
        } else {}
    }
    cout << "a: " << aCnt << "  e: " << eCnt << "  i: " << iCnt
        << "  o: " << oCnt << "  u: " << uCnt << endl;
    
    // 5.10
    aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    while(cin >> ch) {
        switch(ch) {
            case 'a': case 'A':
                ++aCnt;
                break;
            case 'e': case 'E':
                ++eCnt;
                break;
            case 'i': case 'I':
                ++iCnt;
                break;
            case 'o': case 'O':
                ++oCnt;
                break;
            case 'u': case 'U':
                ++uCnt;
                break;
            default:
                break;
        }
    }
    cout << "a: " << aCnt << "  e: " << eCnt << "  i: " << iCnt
        << "  o: " << oCnt << "  u: " << uCnt << endl;

    // 5.11
    aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    int spcCnt = 0, tabCnt = 0, newlCnt = 0;
    
    int chr = 0;
    while((chr = getchar()) != EOF && ch != 2) {
        switch(chr) {
            case 'a': case 'A':
                ++aCnt;
                break;
            case 'e': case 'E':
                ++eCnt;
                break;
            case 'i': case 'I':
                ++iCnt;
                break;
            case 'o': case 'O':
                ++oCnt;
                break;
            case 'u': case 'U':
                ++uCnt;
                break;
            case ' ':
                ++spcCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++newlCnt;
                break;

            default:
                break;
        }
    }
    cout << "a: " << aCnt << "  e: " << eCnt << "  i: " << iCnt
        << "  o: " << oCnt << "  u: " << uCnt << endl << 
        "space: " << spcCnt << "  tab: " << tabCnt << "  newline: " << newlCnt;
    
    // 5.12
    int prev = 0;
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    while((chr = getchar()) != EOF) {
        if('f' == prev) {
            switch(chr) {
                case 'f':
                    ++ffCnt;
                    break;
                case 'l':
                    ++flCnt;
                    break;
                case 'i':
                    ++fiCnt;
                    break;
                default:
                    break;
            }
        }
        prev = chr;
    }
    cout << "ff: " << ffCnt << "  fl: " << flCnt << "  fi: " << fiCnt << endl;

    return 0;
}