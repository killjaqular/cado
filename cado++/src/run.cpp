#pragma once
// Standard Libraries
#include <fstream>
#include <iostream>
#include <list>

// Non-Standard Libraries
#include "scanner.cpp"

using namespace std;

void run(string& inputStream){
    Scanner scanner = Scanner(inputStream);
    list<Token> tokens = scanner.scanTokens();

    for (Token token : tokens){
        // cout << token; // TODO: override the << operator in class Token
    }

    return;
}
