#include <iostream>
#include <string>
#include "core/parser.h"

using namespace simple_engine::core;

int main() {
    Parser parser;
    std::string input;
    std::string currentQuery;

    std::cout << "Welcome to Simple Engine. \nType 'exit;' to quite. \n";
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);

        if (input == "exit;") break;

        // Append input line to current query
        currentQuery += input;
        
        // Check if input ends with semicolon
        if (input.find(';') != std::string::npos) {
            parser.parse(currentQuery);
            currentQuery.clear();
        }
    }
    return 0;
}
