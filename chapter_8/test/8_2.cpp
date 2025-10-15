// 文件输入输出
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "chapter_8/Sales_data.h"
// $ ./8_2 ../test/txt/8_2books.txt ../test/txt/8_2books_out.txt
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

    std::string word;
    std::vector<std::string> wvec;

    if(in.good()) {
        while(in >> word) {
            wvec.push_back(word);
        }
        in.close();
    }
    return wvec;
}

int main(int argc, char *argv[]) {
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

    for(auto line : svec) {
        std::cout << line + "\n";
    }
    std::cout << std::flush;

    // 8.5
    std::vector<std::string> wvec = func_word(file_name);

    for(auto word : wvec) {
        std::cout << word + " ";
    }
    std::cout << std::endl;

    // 8.6
    {
    file_name = argv[1];
    in.open(file_name);

    Sales_data total;
        if(read(in, total)) {
            Sales_data trans;

            while(read(in, trans)) {
                if(trans.isbn() == total.isbn()) {
                    total.combine(trans);
                } else {
                    print(std::cout, total) << std::endl;
                    total = trans;
                }
            }
            print(std::cout, total) << std::endl;
        } else {
            std::cerr << "No data?!" << std::endl;
        }
        in.close();
    }

    // 文件模式
    std::cout << std::fstream::in << " " << std::fstream::out
        << " "<< std::fstream::app << " " << std::fstream::ate << " "
        << std::fstream::trunc << " " << std::fstream::binary << std::endl;

    file_name = "../test/txt/8_2.txt";
    out.open(file_name, std::ofstream::app);

    out << "\nthere is a sentence that output from ../../bin/8_2.exe to this file.\n"
        << std::flush;
    out.close();

    out.open(file_name, std::fstream::out | std::fstream::in);
    out.close();

    // 8.2.2
    // 8.7
    {
        file_name = argv[1];
        std::string out_file("../test/txt/8_2books_out.txt");
        in.open(file_name);
        out.open(out_file);

        Sales_data total;
        if(read(in, total)) {
            Sales_data trans;

            while(read(in, trans)) {
                if(trans.isbn() == total.isbn()) {
                    total.combine(trans);
                } else {
                    print(out, total) << std::endl;
                    total = trans;
                }
            }
            print(out, total) << "\n" << std::endl;
        } else {
            std::cerr << "No data?!" << std::endl;
        }
        
        in.close();
        out.close();
    }

    // 8.8
    {
        file_name = argv[1];
        std::string out_file("../test/txt/8_2books_out.txt");
        in.open(file_name);
        out.open(out_file, std::fstream::app);

        Sales_data total;
        if(read(in, total)) {
            Sales_data trans;

            while(read(in, trans)) {
                if(trans.isbn() == total.isbn()) {
                    total.combine(trans);
                } else {
                    print(out, total) << std::endl;
                    total = trans;
                }
            }
            print(out, total) << "\n" << std::endl;
        } else {
            std::cerr << "No data?!" << std::endl;
        }
        
        in.close();
        out.close();
    }

    return 0;
}