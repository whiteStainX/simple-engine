#include "core/parser_alter_table.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserAlterTable::parse(const std::string& query) {
        std::regex alterTablePattern(
            R"(ALTER\s+TABLE\s+\w+\s+ADD\s+\w+\s+\w+\s*;)",
            std::regex::icase
        );
        if (std::regex_match(query, alterTablePattern)) {
            std::cout << "Valid ALTER TABLE statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core