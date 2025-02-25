#pragma once
#include <string>

namespace simple_engine::core {

    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;

            bool parse(const std::string& query);
        private:
            bool parseSelect(const std::string& query);
            bool parseInsert(const std::string& query);
    };

} // namespace simple_engine::core