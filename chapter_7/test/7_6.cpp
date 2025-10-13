// 类的静态成员
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// 7.6
// 7.57
class Account {
public:
    Account() = default;

    Account(double am) : amount(am) {}

    void calculate() {amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double d);

    double my_amount() { return amount; }

private:
    std::string owner;
    double amount = 0.0;
    static double interestRate;
    static double initRate();    
};

void Account::rate(double newRate) {
    interestRate = newRate;
}

double Account::interestRate = initRate();

double Account::initRate() {
    std::cout << "Initial rate: ";
    std::cin >> interestRate;
    return interestRate;
}

//          //          //          //
class Bar{
public:
    Bar(char ch = init) : aa(init) {} // 静态成员可以作为默认实参

private:
    static Bar mem1; // 静态数据成员可以是不完全类型
    Bar *mem2;
    // Bar mem3;

    char aa;
    static const int init;
};

int main(void) {
    Account a1;

    Account::rate(0.067);

    cout << Account::rate() << endl;
    
    Account a2(10000);
    a2.calculate();
    cout << a2.my_amount() << endl;

    return 0;
}