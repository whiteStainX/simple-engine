#include "core/parser.h"
#include "core/parser_select.h"
#include "core/parser_insert.h"
#include "core/parser_create_table.h"
#include "core/parser_update.h"
#include "core/parser_delete.h"
#include "core/parser_drop_table.h"
#include "core/parser_alter_table.h"
#include <iostream>

namespace simple_engine::core {

    Parser::Parser() {
        operations.emplace_back(std::make_unique<ParserSelect>());
        operations.emplace_back(std::make_unique<ParserInsert>());
        operations.emplace_back(std::make_unique<ParserCreateTable>());
        operations.emplace_back(std::make_unique<ParserUpdate>());
        operations.emplace_back(std::make_unique<ParserDelete>());
        operations.emplace_back(std::make_unique<ParserDropTable>());
        operations.emplace_back(std::make_unique<ParserAlterTable>());
    }

    bool Parser::parse(const std::string& query) {
        for (auto& operation : operations) {
            if (operation->parse(query)) {
                return true;
            }
        }
        std::cout << "Invalid SQL statement. \n";
        return false;
    }

} // namespace simple_engine::core