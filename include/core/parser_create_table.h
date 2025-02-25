#pragma once
#include "parser.h"
#include <string>

namespace simple_engine::core {

    class ParserCreateTable : public ParserOperation {
        public:
            bool parse (const std::string& query) override;
    };

}