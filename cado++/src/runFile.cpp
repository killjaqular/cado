#pragma once
// Standard Libraries
#include <fstream>
#include <iostream>
#include <string>

// Non-Standard Libraries
#include "../inc/common.h"
#include "errorhandling.cpp"
#include "run.cpp"

using namespace std;

void runFile(std::string filePath){
    ifstream inputFile(filePath, ios::binary);

    if (inputFile){
        string inputStream((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        run(inputStream);
        if (ErrorHandling::hadError) exit(LEXICAL_ERROR);
    }else{
        cout << "[x] Failed to open file." << endl;
    }

    return;
}
