#pragma once
#include <iostream>
#include <memory>
using namespace std;

namespace json{

class JsonNode{
public:
    enum Type{
        T_NULL, // nullptr
        T_TRUE, // true
        T_FALSE, // false
        T_NUMBER, // number -> int
        T_STRING, // string
        T_ARRAY, // array
        T_OBJECT, // object
    };
    JsonNode();
    JsonNode(bool);
    Type type();

    string toString();
    shared_ptr<JsonNode> getValue();
    static JsonNode parse(const string &);
private:
    Type type_;
    std::shared_ptr<JsonNode>value_;
};

}