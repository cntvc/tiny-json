#pragma once
#include <iostream>
#include <memory>
using namespace std;

namespace json{

class JsonNode{
public:
    enum Type{
        T_NULL, // nullptr
        T_BOOL, // bool
        T_NUMBER, // number -> int
        T_STRING, // string
        T_ARRAY, // array
        T_OBJECT, // object
    };
    JsonNode();

    Type type();

    string toString();
    shared_ptr<JsonNode> getValue();
    static JsonNode parse(const string &);
private:
    Type type_;
    std::shared_ptr<JsonNode>value_;
};

}