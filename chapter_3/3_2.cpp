// 标准库类型string
#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 定义和初始化string对象
    string s1;
    string s2 = "some thing";
    string s3("any thing");
    string s4 = s3;
    string s5(s4);

    cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl << s5 << endl << endl;

    // string对象上的操作
    // cin cout
    cout << "Enter a string: ";
    cin >> s1;
    cout << s1 << endl << endl;

    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    cout << s1 << ", " << s2 << '!' << endl;

    cin.ignore(100, '\n');

    // empty size
    string line;
    cout << "Enter a stirng: ";
    if(getline(cin, line) && !line.empty()) {
        cout << "\"" << line << "\" " << "is not empty." << endl;
        cout << "size of this string is " << line.size() << endl << endl;
    }

    // string::size_type -> 无符号类型 -> 通常是size_t类型
    decltype(line.size()) len = line.size(); // inline std::size_t std::string::size() const noexcept

    // 比较stirng对象
    s1 = "Hello";
    s2 = "Hello World";
    s3 = "Hiya";
    if(s1 < s2) {
        cout << "s1 < s2" << endl;
    } else {
        cout << "s1 >= s2" << endl;
    }

    if(s2 < s3) {
        cout << "s2 < s3" << endl << endl;
    } else {
        cout << "s2 >= s3" << endl << endl;
    }

    // 为string对象赋值
    cout << "s1 -> " << s1 << "     " << "s2 -> " << s2 << endl;
    s1 = s2;
    cout << "s1 -> " << s1 << "     " << "s2 -> " << s2 << endl << endl;

    // 两个stirng对象相加
    cout << "s1 -> " << s1 << "     " << "s2 -> " << s2 << "     " << "s3 -> " << s3 << endl;
    s1 = s3 + s2;
    s2 += s3;
    cout << "s1 -> " << s1 << "     " << "s2 -> " << s2 << endl << endl;

    // 字面值和string对象相加
    s1 = "hello", s2 = "world";
    s3 = s1 + ", " + s2 + '!';
    cout << "s3: " << s3 << endl;

    s4 = s1 + ", " + "world!";
    cout << "s4: " << s4 << endl << endl; // (s1 + ", ") 的结果是一个string对象

    // s5 = "hello" + ", " + s2; // 错误：("hello" + ", ") 的两个操作数都是字面值

    // 3.2.2
    // 3.2
    /* 
     * string word;
     * while(cin >> word) {
     *    cout << word << ' '; // 会一直从标准输入读取数据，在此注释掉不影响后续的代码
     * }
     */

    // 3.4
    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    if(s1 != s2) {
        if(s1 >= s2) {
            cout << s1 << endl;
        } else {
            cout << s2 << endl;
        }
    }

    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    auto len1 = s1.size(), len2 = s2.size();
    if(len1 != len2) {
        if(len1 >= len2) {
            cout << s1 << endl;
        } else {
            cout << s2 << endl;
        }
    }

    // 3.5
    /* 
     * string total, trans;
     *
     * while(cin >> trans) {
     *     total += trans;
     * }
     * cout << total << endl;
     * 
     * total = "";
     * while(cin >> trans) {
     *     total += trans + ' ';
     * }
     * cout << total << endl;
     */
    
    // 处理stirng对象中的字符
    // 范围for
    string str;
    cout << "range for: ";
    cin >> str;
    for(auto ch : str) {
        cout << ch << ' ';
    }
    cout << endl;

    for(auto &ch : str) { // 必须使用引用才能修改str中的字符
        if(islower(ch)) {
            ch = toupper(ch);
        }
    }

    // 使用下标执行迭代
    cout << "iterator: ";
    cin >> str;
    for(decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index) {
        str[index] = toupper(str[index]);
    }

    // 使用下标执行随机访问
    const string hex_digits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15: ";
    string result;
    string::size_type num = 0;

    while(cin >> num) {
        if(num < hex_digits.size()) {
            result += hex_digits[num];
        }
    }
    cout << result << endl;

    // 3.2.3
    // 3.6
    str = "";
    cout << "Enter a string: ";
    cin >> str;
    for(auto &ch : str) {
        ch = 'X';
    }
    cout << str << endl;

    // 3.10
    result = "";
    cin >> str;
    for(auto ch : str) {
        if(!ispunct(ch)) {
            result += ch;
        }
    }
    cout << result << endl;
     
    return 0;
}