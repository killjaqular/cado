#pragma once
// Standard Libraries
#include <fstream>
#include <iostream>
#include <string>

// Non-Standard Libraries
#include "errorhandling.cpp"
#include "run.cpp"

using namespace std;

void runPrompt(){
    string line;

    while(true){
        cout << ":_> ";
        getline(cin, line);
        if (!line.compare("exit")) break;
        run(line);
        ErrorHandling::hadError = false;
    }

    return;
}
