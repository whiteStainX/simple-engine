#include "core/parser_update.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserUpdate::parse(const std::string& query) {
        std::regex createTablePattern(
            R"(UPDATE\s+\w+\s+SET\s+\w+\s*=\s*'.*'\s*(?:,\s*\w+\s*=\s*'.*')*\s*(WHERE\s+\w+\s*=\s*'.*')?\s*;)",
            std::regex::icase
        );
        if (std::regex_match(query, createTablePattern)) {
            std::cout << "Valid UPDATE statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core