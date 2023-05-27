// Standard Libraries
#include <iostream>
#include <fstream>
#include <string>

// Non-Standard Libraries
#include "run.cpp"

using namespace std;

void runFile(std::string filePath){
    ifstream inputFile(filePath, ios::binary);
    if (inputFile){
        string inputStream((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
        run(inputStream);
    }else{
        cout << "[x] Failed to open file." << endl;
    }

    return;
}
