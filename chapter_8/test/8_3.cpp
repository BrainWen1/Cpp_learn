// string流
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

// 8.3.1
// 8.9
std::istream &func(std::istream &is) {
    std::string str;
    while(is >> str) {
        std::cout << str;
    }

    is.clear();
    return is;
}

int main(void) {
    // 使用istringstream
    // 8.3.1
    // 8.9
    std::istringstream ins("hello");
    func(ins);
    std::cout << std::endl;
    // 8.10
    std::string file_name = "../test/txt/8_3.txt";
    std::ifstream inf(file_name);

    std::string line;
    std::vector<std::string> svec;
    while(std::getline(inf, line)) {
        svec.push_back(line);
    }
    inf.close();

    for(const auto &s : svec) {
        ins.clear();
        ins.str(s);

        std::string word;
        while(ins >> word) {
            std::cout << word << " ";
        }
    }
    std::cout << ins.fail() << ins.eof() << ins.bad() << ins.good();

    // 8.11
    {
        struct PersonInfo {
            std::string name;
            std::vector<std::string> phones;        
        };

        std::string word;
        std::vector<PersonInfo> people;

        std::istringstream record;
        while(std::getline(std::cin, line)) {
            PersonInfo person;

            record.str(line);
            record >> person.name;

            while(record >> word) {
                person.phones.push_back(word);
            }
            record.clear();
            people.push_back(person);
        }
    }

    // 8.3.2
    // 8.13
    {
        struct PersonInfo {
            std::string name;
            std::vector<std::string> phones;        
        };

        std::string word;
        std::vector<PersonInfo> people;

        file_name = "../test/txt/8_3phones.txt";
        inf.open(file_name);

        std::istringstream record;
        while(std::getline(inf, line)) {
            PersonInfo person;

            record.str(line);
            record >> person.name;

            while(record >> word) {
                person.phones.push_back(word);
            }
            record.clear();
            people.push_back(person);
        }

        std::cout << std::endl;
        for(auto &mem : people) {
            std::cout << mem.name << " ";
            for(auto &phone : mem.phones) {
                std::cout << phone << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}