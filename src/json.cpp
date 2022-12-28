#include"json.h"

namespace json{

class JsonBoolean: public JsonValue{
public:
    JsonBoolean(bool value) : JsonValue(JsonType::Boolean), value_(value) {}

    bool get_boolean() const override { return value_; }
    string to_string() const{
        if (value_){
            return "true";
        }
        return "false";
    }
private:
    bool value_;
};

class JsonNull: public JsonValue{
public:
    JsonNull(): JsonValue(JsonType::Null){}
    string to_string() const{
        return "null";
    }
};

static void parseWhitespace(const char *p, size_t &p_index){
    // 跳过空白字符
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
        p++;
        p_index++;
    }
}

static JsonValue* parseContant(const char *p, size_t &p_index, const char *dst, size_t len){
    size_t index = 0;
    while(index < len){
        if(*p != dst[index]){
            p -= index;
            throw runtime_error("format error");
        }
        p++;
        index++;
    }
    
    p_index += len;
    if(*dst == 'f'){
        return new JsonBoolean(false);
    }
    else if (*dst == 't'){
        return new JsonBoolean(true);
    }
    return new JsonNull();
}

static JsonValue* parseValue(const char *p, size_t &p_index){
    switch (*p)
    {
    case 'n':
        return parseContant(p, p_index, "null", 4);
    case 'f':
        return parseContant(p, p_index, "false", 5);
    case 't':
        return parseContant(p, p_index, "true", 4);
    default:
        break;
    }
    return new JsonNull();
}

JsonValue* parse(const string &in){
    const char *p = in.c_str();
    size_t p_index = 0;
    parseWhitespace(p, p_index);
    if (p[p_index] == '}' || p[p_index] == '\0') {
        throw runtime_error("format error");
    }
    JsonValue* res = parseValue(p, p_index);
    parseWhitespace(p, p_index);
    if(p[p_index] != '\0'){
        throw runtime_error("");
    }
    return res;
}

}