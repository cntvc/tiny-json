#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

namespace json{

class JsonValue{
public:
    enum JsonType{
        Null = 0,
        Boolean,
        String,
        Array,
        Object,
        Number,
    };
    JsonValue(JsonType type):type_(type){}
    virtual ~JsonValue(){}
    JsonType get_type() const{
        return type_;
    }

    virtual string get_string() const {
        throw runtime_error("Not a string value");
    }

    virtual double get_number() const{
        throw runtime_error("Not a number value");
    }

    // virtual unordered_map<string, JsonValue>get_object() const{
    //     throw runtime_error("Not a boolean value");
    // }

    virtual vector<JsonValue>get_array() const {
        throw runtime_error("Not a array value");
    }

    virtual bool get_boolean() const {
        throw runtime_error("Not a boolean value"); 
    }

    virtual string to_string() const = 0;

private:
    JsonType type_;
};

JsonValue* parse(const string &);

}
