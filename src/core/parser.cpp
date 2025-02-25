#include "core/parser.h"
#include <iostream>
#include <regex>

namespace simple_engine::core {

    // main entry point for parsing
    bool Parser::parse(const std::string& query) {
        if (parseSelect(query)) return true;
        if (parseInsert(query)) return true;
        if (parseCreateTable(query)) return true;
        if (parseUpdate(query)) return true;
        if (parseDelete(query)) return true;
        if (parseDropTable(query)) return true;
        if (parseAlterTable(query)) return true;
        std::cout << "Invalid SQL statement.\n";
        return false;
    }

    // Recognize SELECT statements
    bool Parser::parseSelect(const std::string& query) {
        std::regex selectPattern(R"(SELECT\s+\*\s+FROM\s+\w+;)", std::regex::icase);
        if (std::regex_match(query, selectPattern)) {
            std::cout << "Valid SELECT statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseInsert(const std::string& query) {
        std::regex insertPattern(
            R"(INSERT\s+INTO\s+\w+\s*\(\s*\w+(?:\s*,\s*\w+)*\s*\)\s*VALUES\s*\(\s*'.*'(?:\s*,\s*'.*')*\s*\);)", 
            std::regex::icase
        );
        if (std::regex_match(query, insertPattern)) {
            std::cout << "Valid INSERT statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseCreateTable(const std::string& query) {
        std::regex createTablePattern(
            R"(CREATE\s+TABLE\s+\w+\s*\(\s*\w+\s+\w+(?:\s*,\s*\w+\s+\w+)*\s*\);)", 
            std::regex::icase
        );
        if (std::regex_match(query, createTablePattern)) {
            std::cout << "Valid CREATE TABLE statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseUpdate(const std::string& query) {
        std::regex updatePattern(
            R"(UPDATE\s+\w+\s+SET\s+\w+\s*=\s*'.*'\s*(?:,\s*\w+\s*=\s*'.*')*\s*(WHERE\s+\w+\s*=\s*'.*')?\s*;)", 
            std::regex::icase
        );
        if (std::regex_match(query, updatePattern)) {
            std::cout << "Valid UPDATE statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseDelete(const std::string& query) {
        std::regex deletePattern(
            R"(DELETE\s+FROM\s+\w+\s*(WHERE\s+\w+\s*=\s*'.*')?\s*;)", 
            std::regex::icase
        );
        if (std::regex_match(query, deletePattern)) {
            std::cout << "Valid DELETE statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseDropTable(const std::string& query) {
        std::regex dropPattern(
            R"(DROP\s+TABLE\s+\w+\s*;)", 
            std::regex::icase
        );
        if (std::regex_match(query, dropPattern)) {
            std::cout << "Valid DROP TABLE statement. \n";
            return true;
        } 
        return false;
    }

    bool Parser::parseAlterTable(const std::string& query) {
        std::regex alterPattern(
            R"(ALTER\s+TABLE\s+\w+\s+ADD\s+\w+\s+\w+\s*;)", 
            std::regex::icase
        );
        if (std::regex_match(query, alterPattern)) {
            std::cout << "Valid ALTER TABLE statement. \n";
            return true;
        } 
        return false;
    }

} // namespace simple_engine::core