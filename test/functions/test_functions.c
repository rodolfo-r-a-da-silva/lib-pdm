#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {
    function_deinit(0U);
    function_set_type(0U, kFunctionTypeNone);
}

void test_Function_SetAndGetType(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(0U, kFunctionTypeAND);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_Function_InitWhenTypeIsNotNone(void) {
    int32_t ret = 0;

    function_set_type(0U, kFunctionTypeAND);
    ret = function_init(0U);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_Function_InitReturnErrorWhenTypeIsNone(void) {
    int32_t ret = function_init(0U);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INIT_TYPE, ret);
}

void test_Function_InitDoesNotChangeType(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(0U, kFunctionTypeAND);
    function_init(0U);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_Function_DeinitDoesNotChangeType(void) {
    FunctionType_t type = kFunctionTypeAND;

    function_set_type(0U, kFunctionTypeAND);
    function_init(0U);
    function_deinit(0U);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_Funtion_ChangingTypeWhenInitializedReturnsErrorAndKeepsType(void) {
    FunctionType_t type = kFunctionTypeAND;
    int32_t ret = 0;

    function_set_type(0U, kFunctionTypeOR);
    function_init(0U);
    ret = function_set_type(0U, type);
    function_get_type(0U, &type);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INITIALIZED, ret);
    TEST_ASSERT_EQUAL(kFunctionTypeOR, type);
}
