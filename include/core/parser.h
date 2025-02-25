#pragma once
#include <string>
#include <memory>
#include <vector>

namespace simple_engine::core {

    // Abstract class
    class ParserOperation {
        public:
            virtual ~ParserOperation() = default;
            virtual bool parse(const std::string& query) = 0;
    };

    class Parser {
        public:
            Parser();
            ~Parser() = default;

            bool parse(const std::string& query);
        private:
            // Create a vector to hold all operations following same pattern
            std::vector<std::unique_ptr<ParserOperation>> operations;
    };

} // namespace simple_engine::core