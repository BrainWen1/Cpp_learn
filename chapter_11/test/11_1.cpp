// 使用关联容器
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

std::string make_plural(size_t ctr, const std::string &word, const std::string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void print(const std::map<std::string, size_t> &mp) {
    for (const auto &w : mp) {
        std::cout << w.first << " occurs " << w.second << " " + make_plural(w.second, "time", "s") << std::endl;
    }
}

int main(void) {
    // 使用map
    std::ifstream in("../test/txt/11_1map.txt");
    if(!in) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }

    std::map<std::string, size_t> word_count;
    std::string word;
    while(in >> word) {
        ++word_count[word];
    }
    in.close();

    print(word_count);

    // 使用set
    std::cout << "------------------------" << std::endl;
    in.open("../test/txt/11_1set.txt");
    if(!in) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }

    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    word_count.clear();
    while(in >> word) {
        if(exclude.find(word) ==  exclude.end()) {
            ++word_count[word];
        }
    }
    in.close();

    print(word_count);

    // 11.1
    // 11.4
    std::cout << "------------------------" << std::endl;
    in.open("../test/txt/11_1map.txt");
    if(!in) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }

    exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    word_count.clear();
    while(in >> word) {
        if(word[0] >= 'A' && word[0] <= 'Z') {
            word[0] += 'a' - 'A';
        }

        if(word[word.size() - 1] == '.' || word[word.size() - 1] == ',' || word[word.size() - 1] == '!' || word[word.size() - 1] == '?') {
            word.erase(word.size() - 1);
        }

        if(exclude.find(word) ==  exclude.end()) {
            ++word_count[word];
        }
    }
    in.close();

    print(word_count);

    return 0;
}