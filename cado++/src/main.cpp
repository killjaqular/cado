/// Standard Libraries
#include <iostream>

#include <stdlib.h>

// Non-Standard Libraries
#include "../inc/common.h"
#include "runFile.cpp"
#include "runPrompt.cpp"

int main(int argc, const char* argv[]){
    std::cout << "Cado in C++" << std::endl;
    if(argc > 2){
        std::cout << USAGE << std::endl;
        exit(EXIT_FAILURE);
    }else if(argc == 2){
        runFile(argv[1]);
    }else{
        runPrompt();
    }

    return EXIT_SUCCESS;
}
