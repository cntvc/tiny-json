#include "json.h"
#include "gtest/gtest.h"

using namespace json;

TEST(test_constant___Test, test_null){
    string s = "null";
    JsonNode value = JsonNode::parse(s);
    
    EXPECT_EQ(value.type(), JsonNode::Type::T_NULL);
    cout << value.toString() << endl;
}

TEST(test_constant___Test, test_failed){
    ASSERT_THROW(JsonNode::parse("n"), invalid_argument);
    ASSERT_THROW(JsonNode::parse("null l"), invalid_argument);
    ASSERT_THROW(JsonNode::parse(""), invalid_argument);
    ASSERT_THROW(JsonNode::parse("nulla"), invalid_argument);
}