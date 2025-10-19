// 额外的string操作
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

void replace_43(std::string &s1, std::string &s2, std::string &s3) {
    size_t len = s2.size();

    for(size_t i = 0; i != s1.size(); ++i) {
        if(s1.at(i) == s2.at(0) && s1.substr(i, len) == s2) {
            s1.erase(s1.begin() + i, s1.begin() + i + len);

            for(size_t j = 0; j != s3.size(); ++j) {
                s1.insert(s1.begin() + i + j, s3[j]);
            }
        }
    }
}

void replace_44(std::string &s1, std::string &s2, std::string &s3) {
    size_t pos = 0;
    size_t len = s2.size();

    while((pos = s1.find(s2, pos)) != std::string::npos) {
        s1.replace(pos, len, s3);
        pos += s3.size();
    }
}

std::string append_45(std::string name, const std::string &prefix, const std::string &suffix) {
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(suffix);
    return name;
}

std::string append_46(std::string name, const std::string &prefix, const std::string &suffix) {
    name.insert(0, prefix);
    name.insert(name.size(), suffix);
    return name;
}

// 9.51
class Date {
private:
    unsigned year, month, day;
    std::unordered_map<std::string, unsigned> monthMap = {
        {"January", 1}, {"Jan", 1}, {"February", 2}, {"Feb", 2},
        {"March", 3}, {"Mar", 3}, {"April", 4}, {"Apr", 4},
        {"May", 5}, {"June", 6}, {"Jun", 6}, {"July", 7}, {"Jul", 7},
        {"August", 8}, {"Aug", 8}, {"September", 9}, {"Sep", 9}, {"Sept", 9},
        {"October", 10}, {"Oct", 10}, {"November", 11}, {"Nov", 11},
        {"December", 12}, {"Dec", 12}
    };

public:
    Date(const std::string& dateStr) {
        std::istringstream iss(dateStr);
        std::string part1, part2, part3;

        iss >> part1 >> part2 >> part3;
        if (monthMap.count(part1)) { // 处理英文格式（如January 1, 1900、Jan 1 1900）
            month = monthMap[part1];
            if (part2.back() == ',') part2.pop_back(); // 处理日的逗号（如"1,"）
            day = std::stoul(part2);
            year = std::stoul(part3);
        } else { // 处理数字格式（如1/1/1990）
            size_t slash1 = dateStr.find('/');
            size_t slash2 = dateStr.find('/', slash1 + 1);
            month = std::stoul(dateStr.substr(0, slash1));
            day = std::stoul(dateStr.substr(slash1 + 1, slash2 - slash1 - 1));
            year = std::stoul(dateStr.substr(slash2 + 1));
        }
    }

    void print() const {
        std::cout << "year: " << year << ", month: " << month << ", day: " << day << std::endl;
    }
};

int main(void) {
    // 9.5.1
    // 9.41
    std::vector<char> cvec{'h', 'e', 'l', 'l', 'o', '!'};

    std::string str(&cvec[0], cvec.size());
    std::cout << str << std::endl;

    // 9.42
    std::string s;
    s.reserve(100);

    // 9.5.2
    // 9.43
    std::string s1("hello, world! wowd"), s2("wo"), s3("910");

    std::cout << s1 << std::endl;
    replace_43(s1, s2, s3);
    std::cout << s1 << std::endl;

    std::cout << "-----" << std::endl;

    // 9.44
    s1 = "hello, world! wowd";
    s2 = "wo";
    s3 = "911";
    std::cout << s1 << std::endl;
    replace_44(s1, s2, s3);
    std::cout << s1 << std::endl;

    // 9.45
    std::string name("Brian"), prefix("Mr."), suffix("III");
    std::cout << name << std::endl;
    name = append_45(name, prefix, suffix);
    std::cout << name << std::endl;

    name = "Brian";
    std::cout << name << std::endl;
    name = append_46(name, prefix, suffix);
    std::cout << name << std::endl;

    // 9.5.3
    // 9.47
    str = std::string("ab2c3d7R4E6");
    std::string numbers("0123456789"), letters("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    size_t pos = 0;
    while((pos = str.find_first_of(numbers, pos)) != std::string::npos) {
        std::cout << str[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;

    pos = 0;
    while((pos = str.find_first_of(letters, pos)) != std::string::npos) {
        std::cout << str[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;

    pos = 0;
    while((pos = str.find_first_not_of(letters, pos)) != std::string::npos) {
        std::cout << str[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;

    pos = 0;
    while((pos = str.find_first_not_of(numbers, pos)) != std::string::npos) {
        std::cout << str[pos] << " ";
        ++pos;
    }
    std::cout << std::endl;

    // 9.49
    const std::string ascenders = "dfhkltDFHKLT";
    const std::string descenders = "gjpqyGJPQY";

    str = "bbacemmnnoorrssuuvvwwxxzz"; 

    size_t max = 0;
    if(str.find_first_of(ascenders + descenders) == std::string::npos) {
        if(str.size() > max) {
            max = str.size();
        }
    }
    std::cout << "max length: " << max << std::endl << std::endl;

    // 9.5.5
    // 9.50
    std::vector<std::string> svec{"12", "66", "1234", "9", "0", "4567", "89", "345"};
    double sum = 0.0;
    for (const auto& s : svec) {
        sum += stod(s);
    }
    std::cout << "sum: " << sum << std::endl;

    // 9.51
    Date d1("January 1, 1900");
    d1.print();
    Date d2("7/12/2007");
    d2.print();
    Date d3("Jan 31 1998");
    d3.print();

    return 0;
}