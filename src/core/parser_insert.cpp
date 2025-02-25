#include "core/parser_insert.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    bool ParserInsert::parse(const std::string& query) {
        std::regex insertPattern(
            R"(INSERT\s+INTO\s+\w+\s*\(\s*\w+(?:\s*,\s*\w+)*\s*\)\s*VALUES\s*\(\s*'.*'(?:\s*,\s*'.*')*\s*\);)",
            std::regex::icase
        );
        if (std::regex_match(query, insertPattern)) {
            std::cout << "Valid INSERT statement .\n";
            return true;
        }
        return false;
    }

} // namespace simple_engine::core