// 使用标准库：文本查询程序
#include <iostream>
#include <string>
#include <fstream>
#include "chapter_12/TextQuery.h"
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include "chapter_12/TextQuery_StrBlob.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while(true) {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    }
}

void runQueries_2(std::ifstream &infile) {
    std::vector<std::string> file;
    std::map<std::string, std::set<size_t>> wm;
    std::string text;
    
    while(std::getline(infile, text)) {
        file.push_back(text);
        
        std::istringstream line(text);
        std::string word;
        while(line >> word) {
            if(!wm.count(word)) {
                wm[word] = std::set<size_t>();
            }
            wm[word].insert(file.size() - 1);
        }
    }

    while(true) {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        }

        // 查找单词并输出结果

        auto loc = wm.find(s);
        if(loc == wm.end()) {
            std::cout << s << " occurs 0 time" << std::endl;;
        } else {
            auto &st = loc->second;
            std::cout << s << " occurs " << st.size() << " " << ((st.size() > 1) ? "times" : "time") << std::endl;

            for(const auto &num : st) {
	            std::cout << "\t(line " << num + 1 << ") " << file[num]  << std::endl;
            }
        }
    }
}

void runQueries_3(std::ifstream &infile) {
    std::vector<std::string> file;
    std::map<std::string, std::set<size_t>> wm;
    std::string text;
    
    while(std::getline(infile, text)) {
        file.push_back(text);
        
        std::istringstream line(text);
        std::string word;
        while(line >> word) {
            if(!wm.count(word)) {
                wm[word] = std::set<size_t>();
            }
            wm[word].insert(file.size() - 1);
        }
    }

    do {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        }

        // 查找单词并输出结果

        auto loc = wm.find(s);
        if(loc == wm.end()) {
            std::cout << s << " occurs 0 time" << std::endl;;
        } else {
            auto &st = loc->second;
            std::cout << s << " occurs " << st.size() << " " << ((st.size() > 1) ? "times" : "time") << std::endl;

            for(const auto &num : st) {
	            std::cout << "\t(line " << num + 1 << ") " << file[num]  << std::endl;
            }
        }
    } while(true);
}

void runQueries_StrBlob(std::ifstream &infile) {
    TextQuery_StrBlob tq(infile);

    while(true) {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;
        if(!(std::cin >> s) || s == "q") {
            break;
        }
        auto ret = tq.query(s);
        print(std::cout, ret) << std::endl;
    }
}

int main(void) {
    std::ifstream infile("../test/txt/12_3.txt");
    if(!infile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    runQueries(infile); // TextQuery构造函数 -> query成员函数 -> QueryResult构造函数 -> print友元函数
    infile.close();

    // 12.3.1
    // 12.28
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    infile.open("../test/txt/12_3.txt");
    if(!infile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    runQueries_2(infile);
    infile.close();

    // 12.29
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    infile.open("../test/txt/12_3.txt");
    if(!infile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    runQueries_3(infile);
    infile.close();

    // 12.32
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    infile.open("../test/txt/12_3.txt");
    if(!infile) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    runQueries_StrBlob(infile);
    infile.close();

    return 0;
}