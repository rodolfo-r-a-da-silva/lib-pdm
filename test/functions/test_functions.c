#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {}

void test_Function_InstanceSetAndGetType(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(0U, kFunctionTypeAND);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_Function_InitDoesNotChangeType(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(0U, kFunctionTypeAND);
    function_init(0U);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_Function_DeinitSetsTypeToNone(void) {
    FunctionType_t type = kFunctionTypeAND;

    function_set_type(0U, kFunctionTypeAND);
    function_init(0U);
    function_deinit(0U);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNone, type);
}
