#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>

class TextQuery;
class QueryResult;

// // // // TextQuery // // // //

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery() = default;
    TextQuery(std::ifstream&);

    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

// // // // QueryResult // // // //

class QueryResult {
    friend std::ostream &print(std::ostream&, const QueryResult&);
public:
    using line_no = std::vector<std::string>::size_type;
    
    QueryResult(const std::string &s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;

};

#endif // TEXTQUERY_H
