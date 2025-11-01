// 使用标准库：文本查询程序
#include <iostream>
#include <string>
#include <fstream>
#include "chapter_12/TextQuery.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while(true) {
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(void) {
    std::ifstream infile("../test/txt/12_3.txt");
    if(!infile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    runQueries(infile);

    return 0;
}