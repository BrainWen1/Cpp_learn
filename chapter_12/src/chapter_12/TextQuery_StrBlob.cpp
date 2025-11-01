#include "chapter_12/TextQuery_StrBlob.h" // TEXTQUERY_H

// Functions //

TextQuery_StrBlob::TextQuery_StrBlob(std::ifstream &infile) : file() {
    std::string text;
    while(std::getline(infile, text)) {
        file.push_back(text);
	    line_no no = file.size() - 1;

	    std::istringstream line(text);
	    std::string word;
	    while(line >> word) {
            auto &lines = wm[word];
	        if(lines == nullptr) {
		        lines.reset(new std::set<line_no>());
	        }
	        lines->insert(no);
	    }
    }
}

QueryResult_StrBlob TextQuery_StrBlob::query(const std::string &sought) const {
    // 用作标记没有要查找的单词的空指针，设为static复用
    static std::shared_ptr<std::set<line_no>> nodata = std::make_shared<std::set<line_no>>();

    // 查找sought
    auto loca = wm.find(sought);
    if(loca == wm.end()) {
	    return QueryResult_StrBlob(sought, nodata, file); // 没找到：返回nodata空指针
    } else {
	    return QueryResult_StrBlob(sought, loca->second, file); // 找到了：返回指向该单词对应的存放行号的集合的智能指针
    }
}

std::string make_plural(size_t i, const std::string &word, const std::string &ending) {
    return (i > 1) ? (word + ending) : word;
}

std::ostream &print(std::ostream &os, QueryResult_StrBlob &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;

    auto it = qr.file.begin();
    for(const auto &num : *qr.lines) {
	    os << "\t(line " << num + 1 << ") " << it.derefer() << std::endl;
        it.increase();
    }
    return os;
}
