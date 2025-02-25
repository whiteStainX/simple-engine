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
            bool parseCreateTable(const std::string& query);
            bool parseUpdate(const std::string& query);
            bool parseDelete(const std::string& query);
            bool parseDropTable(const std::string& query);
            bool parseAlterTable(const std::string& query);
    };

} // namespace simple_engine::core