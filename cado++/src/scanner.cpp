#pragma once
// Standard Libraries
#include <iostream>
#include <list>
#include <string>

// Non-Standard Libraries
#include "errorhandling.cpp"
#include "token.cpp"

using namespace std;

class Scanner{
public:
    string source;
    Scanner(string stream){this->source = stream;};

    list<Token> scanTokens(){
        while (!isAtEnd()) {
            // We are at the beginning of the next lexeme.
            tokenStart = currentChar;
            scanToken();
        }

        tokens.push_back(Token(_EOF, string(""), (char)0, currentLine));
        return tokens;
    };

private:
    list<Token> tokens = list<Token>();

    int tokenStart = 0;
    size_t currentChar = 0;
    size_t currentLine = 1;

    void scanToken(){
        char c = advance();
        switch (c) {
            case '(' :addToken(LEFT_PAREN); break;
            case ')' :addToken(RIGHT_PAREN); break;
            case '{' :addToken(LEFT_BRACE); break;
            case '}' :addToken(RIGHT_BRACE); break;
            case ',' :addToken(COMMA); break;
            case '.' :addToken(DOT); break;
            case '-' :addToken(MINUS); break;
            case '+' :addToken(PLUS); break;
            case ';' :addToken(SEMICOLON); break;
            case '*' :addToken(STAR); break;

            case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
            case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL); break;
            case '<': addToken(match('=') ? LESS_EQUAL : LESS); break;
            case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;

            default:
                ErrorHandling::error(currentLine, string("Unexpected character."));
                cout << "<" << c << ">" << endl;
                break;
        }
    }

    bool match(char expected){
        if (isAtEnd()) return false;
        if (source.at(currentChar) != expected) return false;

        currentChar++;
        return true;
    }

    bool isAtEnd() {
        return currentChar >= source.length();
    }

    char advance() {
        return source.at(currentChar++);
    }

    void addToken(TokenType type) {
        addToken(type, 0);
    }

    void addToken(TokenType type, char literal) {
        string text = source.substr(tokenStart, currentChar);
        tokens.push_back(Token(type, text, literal, currentLine));
    }
};
