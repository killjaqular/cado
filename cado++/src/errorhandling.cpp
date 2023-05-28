#pragma once
// Standard Libraries
#include <iostream>
#include <string>

// Non-Standard Libraries
#include "token.cpp"

using namespace std;

enum ERROR_TYPE{
    GENERAL_ERROR = 1, // General unknown error
    LEXICAL_ERROR, // An error with a lexeme
    SYNTAX_ERROR, // An error with syntax
};

class ErrorHandling{
public:
    // inline allows static data members to be used without being defined outside of the
    // class wherever they are to be used, for example, in main(). This also allows the
    // static member to be initialized in its own class, the way God intended.
    inline static bool hadError = false;

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
