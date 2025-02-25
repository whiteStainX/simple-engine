#include "core/parser_drop_table.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserDropTable::parse(const std::string& query) {
        std::regex createTablePattern(
            R"(DROP\s+TABLE\s+\w+\s*;)",
            std::regex::icase
        );
        if (std::regex_match(query, createTablePattern)) {
            std::cout << "Valid DROP TABLE statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core