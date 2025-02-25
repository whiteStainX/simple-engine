#include "core/parser_create_table.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserCreateTable::parse(const std::string& query) {
        std::regex createTablePattern(
            R"(CREATE\s+TABLE\s+\w+\s*\(\s*\w+\s+\w+(?:\s*,\s*\w+\s+\w+)*\s*\);)",
            std::regex::icase
        );
        if (std::regex_match(query, createTablePattern)) {
            std::cout << "Valid CREATE TABLE statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core