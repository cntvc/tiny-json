#include"json.h"

namespace json{

JsonNode::JsonNode(){
    this->type_ = T_NULL;
    this->value_ = nullptr;
}

JsonNode::Type JsonNode::type(){
    return this->type_;
}

string JsonNode::toString(){
    // return "{\"" + this->getKey() + ":" + this->getValue()->toString() + "}";
    switch (this->type())
    {
    case T_NULL:
        return "null";
        break;
    
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

    static JsonNode parseNull(const string &in, size_t &index){
        static char null[5] = "null";
        for(int i = 0; i < 4; i++){
            if(in[index] != null[i]){
                throw invalid_argument("Json format error");
            }
            index++;
        }
        return JsonNode();
    }

    static JsonNode parseValue(const string &in, size_t &index){
        switch (in[index])
        {
        case 'n':
            return parseNull(in, index);
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