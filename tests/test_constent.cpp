#include "json.h"
#include "gtest/gtest.h"

using namespace json;

TEST(test_constant___Test, test_null){
    JsonValue *p = json::parse("null");
    cout <<  p->to_string() << endl;
}

TEST(test_constant___Test, test_failed){
    ASSERT_THROW(json::parse("n"), runtime_error);
    ASSERT_THROW(json::parse("null l"), runtime_error);
    ASSERT_THROW(json::parse(""), runtime_error);
    ASSERT_THROW(json::parse("nulla"), runtime_error);
}

TEST(test_constant___Test, test_true){
    JsonValue *value = json::parse("false");
    EXPECT_EQ(value->get_type(), JsonValue::Boolean);
    cout << value->to_string() << endl;
}

TEST(test_constant___Test, test_false){
    JsonValue *value = json::parse("true");
    EXPECT_EQ(value->get_type(), JsonValue::Boolean);
    cout << value->to_string() << endl;
}