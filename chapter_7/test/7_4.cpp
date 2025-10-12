// 类的作用域
#include <iostream>
#include <string>

// 7.4.1
// 7.35
typedef std::string Type;
// Type initVal();

class Exercise {
public:
    typedef double Type;
    // Type setVal(Type);
    // Type initVal();
    
private:
    int val;
};

/*
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
*/

int main(void) {
    return 0;
}