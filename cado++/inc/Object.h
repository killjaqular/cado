/// Standard Libraries
#include <stdexcept>
#include <string>

/*
The supported data types are:
boolean
integer
decimal
cadostring
nil
*/

using namespace std;

class Object {
public:
    virtual string toString() const = 0;
};

class plain : public Object {
public:
    string literal;
    char value;
    plain(string literal) {
        this->literal = literal;
        this->value = this->literal[0];
    }

    string toString() const override {
        return this->literal;
    }
};

class boolean : public Object {
public:
    string literal;
    bool value;
    boolean(string literal) {
        this->literal = literal;
        this->value = string("true").compare(this->literal) ? true : false;
    }

    string toString() const override {
        return this->literal;
    }
};

class integer : public Object {
public:
    string literal;
    long long int value;
    integer(string literal) {
        this->literal = literal;
        try {
            this->value = std::stoll(this->literal);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Out of range: " << e.what() << std::endl;
        }
    }

    string toString() const override {
        return this->literal;
    }
};

class decimal : public Object {
public:
    string literal;
    double value;
    decimal(string literal) {
        this->literal = literal;
        try {
            this->value = std::stod(this->literal);
        }catch (const std::invalid_argument& e) {
            std::cout << "Invalid argument: " << e.what() << std::endl;
        }catch (const std::out_of_range& e) {
            std::cout << "Out of range: " << e.what() << std::endl;
        }
    }

    string toString() const override {
        return this->literal;
    }
};

class cadostring : public Object {
public:
    string literal;
    string value;
    cadostring(string literal) {
        this->literal = literal;
        this->value = this->literal;
    }

    string toString() const override {
        return this->literal;
    }
};

class nil : public Object {
public:
    string literal;
    void* value = NULL;
    nil(string literal) {
        this->literal = literal;
        this->value = NULL;
    }

    string toString() const override {
        return this->literal;
    }
};
