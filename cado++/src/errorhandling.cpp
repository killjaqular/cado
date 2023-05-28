#pragma once
// Standard Libraries
#include <iostream>
#include <string>

// Non-Standard Libraries
#include "token.cpp"

using namespace std;

enum ERROR_TYPE{
    LEXICAL_ERROR = 1, // Basic lexical error
    SYNTAX_ERROR,
};

class ErrorHandling{
public:
    static bool hadError;

    static void error(size_t line, string message){
        report(line, "", message);
        return;
    }

private:

    static void report(size_t line, string where, string message){
        cout << "[x] Error in line " << line << where << ": " << message << endl;
        hadError = true;
        return;
    }
};
