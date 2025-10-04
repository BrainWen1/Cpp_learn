// try语句块和异常处理
#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 5.6.3
    // 5.23 5.24 5.25
    int num1 = 0, num2 = 0;
    while(true) {
        try {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;

            if(!cin) {
                throw std::runtime_error("Input Error!");
            } else if(num2 == 0) {
                throw std::runtime_error("num_2 cannot be ZERO!");
            }

            cout << num1 / num2 << endl;
            break;

        } catch(std::runtime_error& err) {
            cout << err.what() << endl;

            cout << "Try again? (Y/N)" << endl;
            char ch = 0;
            cin >> ch;

            if(ch == 'Y' || ch == 'y') {
            } else if(ch == 'N' || ch == 'n') {
                break;
            } else {
                cout << "Error" << endl;
                break;
            }
        }
    }

    return 0;
}