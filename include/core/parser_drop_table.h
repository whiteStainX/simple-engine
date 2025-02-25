#pragma once
#include "parser.h"
#include <string>

namespace simple_engine::core {

    class ParserDropTable : public ParserOperation {
        public:
            bool parse (const std::string& query) override;
    };

}