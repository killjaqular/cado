/// Standard Libraries
#include <iostream>
#include <list>
#include <string>

#include <stdlib.h>

// Non-Standard Libraries
#include "../inc/common.h"
#include "errorhandling.cpp"
#include "runFile.cpp"
#include "runPrompt.cpp"

using namespace std;

bool ErrorHandling::hadError = false;

int main(int argc, const char* argv[]){
    cout << "Cado in C++" << endl;
    if(argc > 2){
        cout << USAGE << endl;
        exit(EXIT_FAILURE);
    }else if(argc == 2){
        runFile(argv[1]);
        if (ErrorHandling::hadError) exit(LEXICAL_ERROR);
    }else{
        runPrompt();
    }

    return EXIT_SUCCESS;
}
