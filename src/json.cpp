#include"json.h"

namespace json{

JsonNode::JsonNode(){
    this->type_ = T_NULL;
    this->value_ = nullptr;
}

JsonNode::JsonNode(bool value){
    if(value){
        this->type_ = T_TRUE;
    }else{
        this->type_ = T_FALSE;
    }

    this->value_ = nullptr;
}

JsonNode::Type JsonNode::type(){
    return this->type_;
}

string JsonNode::toString(){
    // return "{\"" + this->getKey() + ":" + this->getValue()->toString() + "}";
    switch (this->type())
    {
    case T_NULL: return "null";
    case T_TRUE: 
        return "true";
    case T_FALSE:
        return "false";
    default:
        break;
    }
    return "";
}


static void parseWhitespace(const string &in, size_t &index){
    while(index < in.size()){
        char c = in[index];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r'){
            index++;
        }else{
            break;
        }
    }
}

static JsonNode parseContant(const string &in, const string temp, size_t &index, JsonNode::Type t){
    int res = in.compare(0, temp.size(), temp);
    if(res != 0){
        throw invalid_argument("Json format error");
    }
    index += temp.size();
    if(t == JsonNode::T_TRUE){
        return JsonNode(true);
    }else if (t == JsonNode::T_FALSE){
        return JsonNode(false);
    }
    return JsonNode();
}

static JsonNode parseValue(const string &in, size_t &index){
    switch (in[index])
    {
    case 'n': return parseContant(in, "null", index, JsonNode::T_NULL);
    case 'f': return parseContant(in, "false", index, JsonNode::T_FALSE);
    case 't': return parseContant(in, "true", index, JsonNode::T_TRUE);
    default:
        break;
    }
    return JsonNode();
}



JsonNode JsonNode::parse(const string &in){
    size_t index = 0;
    
    parseWhitespace(in, index);
    if(index == in.size()){
        throw invalid_argument("has no json data");
    }
    JsonNode node = parseValue(in, index);
    parseWhitespace(in, index);
    if(in[index] != '\0'){
        throw invalid_argument("Json format error, missing terminator");
    }
    return node;
}


}