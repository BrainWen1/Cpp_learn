#include <iostream>
#include "chapter_6/chapter_6.h"

using std::cin;
using std::cout;
using std::endl;

// 6.1
// 6.3
int fact(int val) {
    int ret = 1;
    
    while(val > 1) {
        ret *= val;
        --val;
    }
    return ret;
}

// 6.4
int fact_x(void) {
    int val = 0;
    cout << "Enter a number: ";
    cin >> val;

    int ret = 1;
    while(val > 1) {
        ret *= val;
        --val;
    }
    return ret;
}

// 6.5
unsigned absolute(int val) {
    if(val >= 0) {
        return static_cast<unsigned> (val);
    } else {
        return static_cast<unsigned> (-val);
    }
}

// 6.7
int count_calls() {
    static size_t count = 0;
    return count++;
}