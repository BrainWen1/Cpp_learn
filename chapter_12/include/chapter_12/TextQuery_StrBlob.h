#ifndef TEXTQUERY_STRBLOB_H
#define TEXTQUERY_STRBLOB_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include "chapter_12/StrBlob.h"

class TextQuery_StrBlob;
class QueryResult_StrBlob;

// // // // TextQuery_StrBlob // // // //

class TextQuery_StrBlob {
public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery_StrBlob() = default;
    TextQuery_StrBlob(std::ifstream&);

    QueryResult_StrBlob query(const std::string&) const;

private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

// // // // QueryResult_StrBlob // // // //

class QueryResult_StrBlob {
    friend std::ostream &print(std::ostream&, QueryResult_StrBlob&);
public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult_StrBlob(const std::string &s, std::shared_ptr<std::set<line_no>> p, StrBlob f)
        : sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    StrBlob file;

};

#endif // TEXTQUERY_STRBLOB_H
