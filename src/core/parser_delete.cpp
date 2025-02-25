#include "core/parser_delete.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserDelete::parse(const std::string& query) {
        std::regex createTablePattern(
            R"(DELETE\s+FROM\s+\w+\s*(WHERE\s+\w+\s*=\s*'.*')?\s*;)",
            std::regex::icase
        );
        if (std::regex_match(query, createTablePattern)) {
            std::cout << "Valid DELETE statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core