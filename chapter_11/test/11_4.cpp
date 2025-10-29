// 无序容器
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>

void print(const std::unordered_set<int>& us) {
    std::cout << "Unordered Set elements: ";
    for (const auto& elem : us) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}


void print(const std::unordered_map<std::string, int>& um) {
    std::cout << "Unordered Map elements: ";
    for (const auto& pair : um) {
        std::cout << pair.first << " => " << pair.second << " ";
    }
    std::cout << std::endl;
}

class node {
public:
    node(int i, const std::string& s) : id(i), name(s) {}
    int id;
    std::string name;
};

size_t hasher(const node& n) {
    return std::hash<int>()(n.id) ^ std::hash<std::string>()(n.name);
}

bool eqOp(const node& n1, const node& n2) {
    return n1.id == n2.id && n1.name == n2.name;
}

// 11.4
// 11.38
std::string make_plural(size_t ctr, const std::string &word, const std::string &ending) {
    return (ctr > 1) ? word + ending : word;
}

void print(const std::unordered_map<std::string, size_t> &mp) {
    for (const auto &w : mp) {
        std::cout << w.first << " occurs " << w.second << " " + make_plural(w.second, "time", "s") << std::endl;
   }
}

std::unordered_map<std::string, std::string> buildMap(std::ifstream &map_file) {
    std::unordered_map<std::string, std::string> trans_map;

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

std::string transform(std::string word, std::unordered_map<std::string, std::string> trans_map) {
    if(trans_map.find(word) != trans_map.end()) {
        return trans_map[word];
    } else {
        return word;
    }
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
    std::unordered_map<std::string, std::string> trans_map = buildMap(map_file);

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
    // 使用无序容器
    std::unordered_set<int> us = {1, 2, 3, 4, 5};
    us.insert(3); // 插入重复元素不会改变集合
    print(us);

    std::unordered_map<std::string, int> um;
    um["apple"] = 1;
    um["banana"] = 2;
    um["orange"] = 3;
    print(um);

    // 管理桶
    std::cout << "-------------------------------" << std::endl;
    size_t n = us.bucket_count();
    std::cout << "Number of buckets in unordered_set: " << n << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Bucket " << i << " has " << us.bucket_size(i) << " elements." << std::endl;
    }

    n = um.bucket_count();
    std::cout << "Number of buckets in unordered_map: " << n << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << "Bucket " << i << " has " << um.bucket_size(i) << " elements." << std::endl;
    }

    std::cout << "-------------------------------" << std::endl;
    std::cout << "Max bucket count in unordered_set: " << us.max_bucket_count() << std::endl;
    std::cout << "Max bucket count in unordered_map: " << um.max_bucket_count() << std::endl;

    std::cout << "-------------------------------" << std::endl;
    std::cout << "\"3\" is in bucket: " << us.bucket(3) << std::endl;
    std::cout << "\"banana\" is in bucket: " << um.bucket("banana") << std::endl;

    // 哈希策略
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Load factor of unordered_set: " << us.load_factor() << std::endl;
    std::cout << "Load factor of unordered_map: " << um.load_factor() << std::endl;

    std::cout << "Max load factor of unordered_set: " << us.max_load_factor() << std::endl;
    std::cout << "Max load factor of unordered_map: " << um.max_load_factor() << std::endl;

    // rehash 和 reserve
    std::cout << "-------------------------------" << std::endl;
    us.rehash(20);
    std::cout << "After rehash to 20 buckets, bucket count of unordered_set: " << us.bucket_count() << std::endl;

    um.reserve(10);
    std::cout << "After reserve for 10 elements, bucket count of unordered_map: " << um.bucket_count() << std::endl;

    // 无序容器对关键字类型的要求
    std::cout << "-------------------------------" << std::endl;
    std::hash<int> int_hash;
    std::cout << "Hash value for 42: " << int_hash(42) << std::endl;

    std::hash<std::string> str_hash;
    std::cout << "Hash value for \"hello\": " << str_hash("hello") << std::endl;

    std::hash<std::shared_ptr<int>> ptr_hash;
    std::shared_ptr<int> p = std::make_shared<int>(42);
    std::cout << "Hash value for shared_ptr<int>: " << ptr_hash(p) << std::endl;

    // 自定义类型的哈希函数
    std::cout << "-------------------------------" << std::endl;
    std::unordered_set<node, decltype(hasher)*, decltype(eqOp)*> node_set(10, hasher, eqOp);
    node_set.emplace(1, "Node1");
    node_set.emplace(2, "Node2");
    node_set.emplace(3, "Node3");
    for (const auto& n : node_set) {
        std::cout << "Node ID: " << n.id << ", Name: " << n.name << std::endl;
    }

    // 11.4
    // 11.38
    // 单词计数程序
    std::cout << "-------------------------------" << std::endl;
    std::ifstream in("../test/txt/11_1map.txt");
    if(!in) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while(in >> word) {
        ++word_count[word];
    }
    in.close();

    print(word_count);

    // 单词转换程序
    std::cout << "-------------------------------" << std::endl;
    std::ifstream map_file("../test/txt/11_3rule.txt");
    std::ifstream input("../test/txt/11_3test.txt");
    word_transform(map_file, input);

    return 0;
}