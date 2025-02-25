#include "core/parser_select.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserSelect::parse(const std::string& query) {
        std::regex selectPattern(
            R"(SELECT\s+\*\s+FROM\s+\w+;)",
            std::regex::icase
        );
        if (std::regex_match(query, selectPattern)) {
            std::cout << "Valid SELECT statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core