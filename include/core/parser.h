#pragma once
#include <string>

namespace simple_engine::core {

    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;

            // Basic method to parse simple SQL SELECT statements
            bool parse(const std::string& query);
    };

} // namespace simple_engine::core