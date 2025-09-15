// 文件重定向: ./filename.exe < infile.txt > outfile.txt
#include <iostream>

int main(void) {
    int a = 0, b = 0;
    std::cin >> a >> b; // 78 123

    std::cout << "a + b = " << a + b << std::endl; // a + b = 201

    return 0;
}