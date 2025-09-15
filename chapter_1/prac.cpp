#include <iostream>

int main(void) {

    // 初始输入输出
    std::cout << "Hello, World!" << std::endl;

    int v1 = 0, v2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;

    std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

    std::cout << "The result of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;

    std::cout << "The sum of " << v1
              << " and " << v2
              << " is " << v1 + v2 << std::endl;

    // 规范化注释
    /* 
     * 这是一些注释的第一行
     * 这是一些注释的第二行
     * 这是一些注释的第三行
     */

    // /* 这是一些使用了不合法的 /*嵌套注释*/ 的语句 */

    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */;
    std::cout << /* "*/" /* "/*" */;

    // 控制流
    int sum = 0, val = 50;
    while(val <= 100) {
        sum += val;
        val++;
    }
    std::cout << "\nSum of 50 to 100 inclusive is " << sum << std::endl;
    
    //
    val = 10;
    while(val >= 0) {
        std::cout << val << ' ';
        val--;
    }
    std::cout << std::endl;
    
    //
    std::cout << "Enter two numbers:";
    std::cin >> v1 >> v2;
    if(v1 > v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }

    while(v1 <= v2) {
        std::cout << v1 << ' ';
        v1++;
    }
    std::cout << std::endl;

    //
    sum = 0;
    for(int i = -100; i <= 100; ++i) {
        sum += i;
    }
    std::cout << "Sum of -100 to 100 inclusive is " << sum << std::endl;

    // 1.4.1
    //
    sum = 0;
    for(int val = 50;  val <= 100; val++) {
        sum += val;
    }
    std::cout << "\nSum of 50 to 100 inclusive is " << sum << std::endl;

    //
    for(int i = 10; i >= 0; --i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    
    //
    std::cout << "Enter two numbers:";
    std::cin >> v1 >> v2;
    if(v1 > v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    for(int i = v1; i <= v2; ++i) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    //
    /*
     * sum = 0;
     * while(std::cin >> val) {
     *     sum += val;
     * }
     * std::cout << "Sum of numbers is " << sum << std::endl;
     */

    //
    int currVal = 0;
    val = 0;
    if(std::cin >> currVal) {
        int cnt  = 1;

        while(std::cin >> val) {
            if(val == currVal) {
                cnt++;
            } else {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;

                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }

    return 0;
}