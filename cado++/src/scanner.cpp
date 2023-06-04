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

        tokens.push_back(Token(_EOF, string("EOF"), new plain(string("")), currentLine));
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
            case '(' :addToken(LEFT_PAREN, c); break;
            case ')' :addToken(RIGHT_PAREN, c); break;
            case '{' :addToken(LEFT_BRACE, c); break;
            case '}' :addToken(RIGHT_BRACE, c); break;
            case ',' :addToken(COMMA, c); break;
            case '.' :addToken(DOT, c); break;
            case '-' :addToken(MINUS, c); break;
            case '+' :addToken(PLUS, c); break;
            case ';' :addToken(SEMICOLON, c); break;
            case '*' :addToken(STAR, c); break;

            case '!': {
                if (match('=')) {
                    addToken(BANG_EQUAL, "!=");
                }else{
                    addToken(BANG, c);
                }
                break;
            }
            case '=': {
                if (match('=')) {
                    addToken(EQUAL_EQUAL, "==");
                }else{
                    addToken(EQUAL, c);
                }
                break;
            }
            case '<': {
                if (match('=')) {
                    addToken(LESS_EQUAL, "<=");
                }else{
                    addToken(LESS, c);
                }
                break;
            }
            case '>': {
                if (match('=')) {
                    addToken(GREATER_EQUAL, ">=");
                }else{
                    addToken(GREATER, c);
                }
                break;
            }

            case '/':
                if (match('/')) {
                    // A comment goes until the end of the line.
                    while (peek() != '\n' && !isAtEnd()) advance();
                }else{
                    addToken(SLASH, c);
                }
                break;

            // Ignore all whitespace.
            case ' ':
            case '\r':
            case '\t':
                break;

            case '\n': currentLine++; break;

            case '"': makeString(); break;

            default:
                ErrorHandling::error(currentLine, string("Unexpected character."));
                cout << "<" << c << ">" << endl;
                break;
        }
    }

    void makeString() {
        while (peek() != '"' && !isAtEnd()) {
            if (peek() == '\n') currentLine++;
            advance();
        }

        if (isAtEnd()) {
            ErrorHandling::error(currentLine, "Unterminated string.");
            return;
        }

        // The closing ".
        advance();

        // Trim the surrounding quotes.
        string value = source.substr(tokenStart + 1, currentChar - 1);
        addToken(STRING, value);
    }

    char peek() {
        if (isAtEnd()) return '\0';
        return source.at(currentChar);
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
        Object* object = new plain(string(1, literal));
        string text = source.substr(tokenStart, currentChar);
        tokens.push_back(Token(type, text, object, currentLine));
    }

    void addToken(TokenType type, string literal) {
        Object* object = new cadostring(literal);
        string text = source.substr(tokenStart, currentChar);
        tokens.push_back(Token(type, text, object, currentLine));
    }
};
