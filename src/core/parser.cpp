#include "core/parser.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    // main entry point for parsing
    bool Parser::parse(const std::string& query) {
        if (parseSelect(query)) return true;
        if (parseInsert(query)) return true;
        std::cout << "Invalid SQL statement.\n";
        return false;
    }

    // Recognize SELECT statements
    bool Parser::parseSelect(const std::string& query) {
        std::regex selectPattern(R"(SELECT\s+\*\s+FROM\s+\w+;)", std::regex::icase);
        if (std::regex_match(query, selectPattern)) {
            std::cout << "Valid SELECT statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseInsert(const std::string& query) {
        std::regex insertPattern(
            R"(INSERT\s+INTO\s+\w+\s*\(\s*\w+(?:\s*,\s*\w+)*\s*\)\s*VALUES\s*\(\s*'.*'(?:\s*,\s*'.*')*\s*\);)", 
            std::regex::icase
        );
        if (std::regex_match(query, insertPattern)) {
            std::cout << "Valid INSERT statement. \n";
            return true;
        } 
        return false;
    }

} // namespace simple_engine::core