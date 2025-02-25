#include "core/parser.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool Parser::parse(const std::string& query) {
        std::regex selectPattern(R"(SELECT\s+\*\s+FROM\s+\w+;)", std::regex::icase);
        if (std::regex_match(query, selectPattern)) {
            std::cout << "Valid SELECT statement. \n";
            return true;
        } else {
            std::cout << "Invalid SQL statement. \n";
            return false;
        }
    }

} // namespace simple_engine::core