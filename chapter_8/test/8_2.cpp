// 文件输入输出
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> func_line(std::string file_name) {
    std::ifstream in(file_name);

    std::string line;
    std::vector<std::string> svec;

    if(in.good()) {
        while(std::getline(in, line)) {
            svec.push_back(line);
        }
        in.close();
    }
    return svec;
}

std::vector<std::string> func_word(std::string file_name) {
    std::ifstream in(file_name);

    std::string line;
    std::vector<std::string> svec;

    if(in.good()) {
        while(std::getline(in, line)) {
            svec.push_back(line);
        }
        in.close();
    }
    return svec;
}

int main(void) {
    std::string file_name("../test/txt/8_2.txt");

    std::ifstream in(file_name);
    std::ofstream out;

    std::string str;
    if(in.good()) {
        while(in >> str) {
            std::cout << str << " " << std::flush;
        }
    } else {
        std::cerr << "in is not good!" << std::endl;
    }
    in.close();

    out.open(file_name, std::ofstream::app);
    if(out.good()) {

    } else {
        std::cerr << "out is not good!" << std::endl;
    }
    out.close();

    // 8.2.1
    // 8.4
    std::vector<std::string> svec = func_line(file_name);

    for(auto mem : svec) {
        std::cout << mem + "\n";
    }
    std::cout << std::flush;

    // 8.5
    std::vector<std::string> wvec = func_word(file_name);

    for(auto mem : svec) {
        std::cout << mem + "\n";
    }
    std::cout << std::flush;

    return 0;
}