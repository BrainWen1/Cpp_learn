// 关联容器操作
# include <iostream>
# include <map>
# include <set>
# include <vector>
# include <string>
# include <iterator>
# include <algorithm>
# include <fstream>
# include <sstream>

inline void print(std::multiset<std::string>& c) {
    for (const auto& s : c) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

inline void print(std::vector<std::string>& v) {
    for (const auto& s : v) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

inline void print(std::set<int>& s) {
    for (const auto& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

inline void print(std::map<int, char>& m) {
    for (const auto& pair : m) {
        std::cout << pair.first << " => " << pair.second << " ";
    }
    std::cout << std::endl;
}

void print(std::multiset<int>& ms) {
    for (const auto& elem : ms) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void print(std::multimap<int, char>& mm) {
    for (const auto& pair : mm) {
        std::cout << pair.first << " => " << pair.second << " ";
    }
    std::cout << std::endl;
}

void print(std::map<std::string, int>& word_count) {
    for (const auto& w : word_count) {
        std::cout << w.first << " occurs " << w.second << " | ";
    }
    std::cout << std::endl;
}

void print(std::multimap<std::string, std::string>& authors) {
    for (const auto& pair : authors) {
        std::cout << pair.first << " => " << pair.second << " | ";
    }
    std::cout << std::endl;
}

// 11.3.6
// 11.33
std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::map<std::string, std::string> trans_map;

    std::string key, value;
    while(map_file >> key && std::getline(map_file, value)) {
        if(value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            throw std::runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

std::string transform(std::string word, std::map<std::string, std::string> trans_map) {
    if(trans_map.find(word) != trans_map.end()) {
        return trans_map[word];
    } else {
        return word;
    }
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    std::map<std::string, std::string> trans_map = buildMap(map_file);

    std::string text;
    while(std::getline(input, text)) {
        std::istringstream stream(text);
        std::string word;

        bool firstword = true;
        while(stream >> word) {
            if(firstword) {
                firstword = false;
            } else {
                std::cout << " ";
            }

            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

int main(void) {
    // 类型别名
    std::map<int, char>::value_type v1; // std::pair<const int, char>
    std::set<int>::value_type v2;       // int
    std::map<int, char>::key_type k1;   // int
    std::set<int>::key_type k2;         // int
    std::map<int, char>::mapped_type m1; // char

    std::set<int> s;
    s.insert(42); // 插入一个整数
    std::set<int>::iterator it = s.find(42); // 查找整数42
    if (it != s.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::map<int, char> m;
    m.insert(std::make_pair(1, 'a')); // 插入键值对
    std::map<int, char>::iterator mit = m.find(1); // 查找键1
    if (mit != m.end()) {
        std::cout << "Found: " << mit->first << " -> " << mit->second << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::map<int, char>::iterator it_map = m.begin();
    // it_map->first = 2; // 错误：不能修改键
    it_map->second = 'b'; // 正确：可以修改值

    std::set<int>::iterator it_set = s.begin();
    // *it_set = 43; // 错误：不能修改集合中的元素

    // 遍历关联容器
    for(const auto& pair : m) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    for(const auto& elem : s) {
        std::cout << elem << std::endl;
    }

    // 11.3.1
    // 11.16
    std::cout << "-------------------------------" << std::endl;
    it_map->second = 'c'; // 修改值
    std::cout << "After modification: " << it_map->first << " -> " << it_map->second << std::endl;

    // 11.17
    std::cout << "-------------------------------" << std::endl;
    std::multiset<std::string> c({"apple", "banana", "apple", "orange"});
    std::vector<std::string> v({"grape", "melon", "kiwi"});

    std::copy(v.begin(), v.end(), std::inserter(c, c.end()));
    // std::copy(v.begin(), v.end(), std::back_inserter(c));

    std::copy(c.begin(), c.end(), std::inserter(v, v.end()));
    std::copy(c.begin(), c.end(), std::back_inserter(v));

    print(c);
    print(v);

    // 添加元素
    std::cout << "-------------------------------" << std::endl;
    print(s);
    s.insert(100);
    s.insert(200);
    s.insert(100); // 重复元素不会被添加
    print(s);

    print(m);
    m.insert(std::make_pair(2, 'x'));
    m.insert(std::make_pair(1, 'y')); // 重复键不会被添加
    print(m);

    auto p = m.insert(std::make_pair(3, 'z'));
    if(p.second) {
        std::cout << "Inserted: " << p.first->first << " -> " << p.first->second << std::endl;
    } else {
        std::cout << "Key already exists: " << p.first->first << std::endl;
    }

    // 向multiset multimap添加元素
    std::cout << "-------------------------------" << std::endl;
    std::multiset<int> ms;
    ms.insert(10);
    ms.insert(10); // 允许重复元素
    print(ms);

    std::multimap<int, char> mm;
    mm.insert(std::make_pair(1, 'a'));
    mm.insert(std::make_pair(1, 'b')); // 允许重复键
    print(mm);
    
    // 11.3.2
    // 11.20
    std::cout << "-------------------------------" << std::endl;
    std::ifstream in;
    in.open("../test/txt/11_1map.txt");
    if(!in) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }

    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    std::map<std::string, int> word_count;
    std::string word;

    while(in >> word) {
        if(word[0] >= 'A' && word[0] <= 'Z') {
            word[0] += 'a' - 'A';
        }

        if(word[word.size() - 1] == '.' || word[word.size() - 1] == ',' || word[word.size() - 1] == '!' || word[word.size() - 1] == '?') {
            word.erase(word.size() - 1);
        }

        if(exclude.find(word) ==  exclude.end()) {
            if(word_count.find(word) == word_count.end()) {
                word_count.insert(std::make_pair(word, 1));
            } else {
                word_count.find(word)->second += 1;         
            }
        }
    }
    in.close();

    print(word_count);

    // 在multiset和multimap中查找元素
    std::cout << "-------------------------------" << std::endl;
    std::multiset<std::string> ms_words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    std::string target = "banana";
    auto count = ms_words.count(target);
    std::cout << target << " occurs " << count << " times in the multiset." << std::endl;

    auto ms_it = ms_words.find(target);
    if(ms_it != ms_words.end()) {
        for(size_t i = 0; i < count; ++i) {
            std::cout << *ms_it << " ";
            ++ms_it;
        }
        std::cout << std::endl;
    } else {
        std::cout << target << " not found in the multiset." << std::endl;
    }

    // lower_bound 和 upper_bound
    std::cout << "-------------------------------" << std::endl;
    std::multimap<int, char> mm_pairs = {{1, 'a'}, {2, 'b'}, {1, 'c'}, {3, 'd'}, {2, 'e'}};
    int key = 2;
    auto lower = mm_pairs.lower_bound(key);
    auto upper = mm_pairs.upper_bound(key);
    std::cout << "Elements with key " << key << ": ";
    for(auto it = lower; it != upper; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    // equal_range
    std::cout << "-------------------------------" << std::endl;
    key = 1;
    auto range = mm_pairs.equal_range(key);
    std::cout << "Elements with key " << key << ": ";
    for(auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    // 11.3.5
    // 11.31
    std::cout << "-------------------------------" << std::endl;
    std::multimap<std::string, std::string> authors = {
        {"Smith", "C++ Primer"},
        {"Johnson", "Effective C++"},
        {"Smith", "The C++ Programming Language"},
        {"Brown", "Design Patterns"},
        {"Johnson", "More Effective C++"}
    };
    std::string search_author = "Smith";
    auto au_it = authors.find(search_author);
    if(au_it != authors.end()) {
        auto range = authors.equal_range(search_author);
        std::cout << "Books by " << search_author << ": ";
        for(auto it = range.first; it != range.second; ++it) {
            std::cout << it->second << "; ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No books found by " << search_author << std::endl;
    }

    au_it = authors.erase(au_it); // 删除当前迭代器位置的元素，并返回指向被删元素之后位置的迭代器
    au_it = authors.erase(au_it);
    print(authors);

    // 11.32
    std::cout << "-------------------------------" << std::endl;
    authors.insert({"Smith", "C++ Concurrency in Action"});
    authors.insert({"Smith", "Accelerated C++"});
    // 按字典序打印作者以及作品（仅使用 authors）
    // authors 是 multimap，作者键有序；对同一作者的作品收集后排序再输出
    {
        for (auto it = authors.cbegin(); it != authors.cend(); ) {
            const std::string &author = it->first;
            auto range = authors.equal_range(author);

            std::vector<std::string> titles;
            titles.reserve(std::distance(range.first, range.second));
            for (auto jt = range.first; jt != range.second; ++jt) {
                titles.push_back(jt->second);
            }
            std::sort(titles.begin(), titles.end());

            std::cout << author << ": ";
            for (const auto &t : titles) {
                std::cout << t << "; ";
            }
            std::cout << std::endl;

            it = range.second; // 跳到下一个作者
        }
    }

    // 单词转换程序
    std::cout << "-------------------------------" << std::endl;
    std::ifstream map_file("../test/txt/11_3rule.txt");
    std::ifstream input("../test/txt/11_3test.txt");
    word_transform(map_file, input);

    return 0;
}