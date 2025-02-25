#pragma once
#include "parser.h"
#include <string>

namespace simple_engine::core {

    class ParserDelete : public ParserOperation {
        public:
            bool parse (const std::string& query) override;
    };

}