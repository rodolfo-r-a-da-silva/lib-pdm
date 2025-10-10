#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {}

void test_GetAndSetType_ReturnsNoErrorWhenNotInit(void) {
    FunctionHandle_t hFunction = { 0 };
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&hFunction, kFunctionTypeAND);
    function_get_type(&hFunction, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_InitWhenTypeIsNotNone_ReturnsNoError(void) {
    FunctionHandle_t hFunction = { 0 };
    int32_t ret = 0;

    function_set_type(&hFunction, kFunctionTypeAND);
    ret = function_init(&hFunction);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_InitWhenTypeIsNone_ReturnsTypeError(void) {
    FunctionHandle_t hFunction = { 0 };
    int32_t ret = function_init(&hFunction);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INIT_TYPE, ret);
}

void test_InitDoesNotChangeChangeType(void) {
    FunctionHandle_t hFunction = { 0 };
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&hFunction, kFunctionTypeAND);
    function_init(&hFunction);
    function_get_type(&hFunction, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_DeinitDoesNotChangeType(void) {
    FunctionHandle_t hFunction = { 0 };
    FunctionType_t type = kFunctionTypeAND;

    function_set_type(&hFunction, kFunctionTypeAND);
    function_init(&hFunction);
    function_deinit(&hFunction);
    function_get_type(&hFunction, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeAND, type);
}

void test_ChangeTypeWhenInitialized_ReturnsErrorAndKeepsType(void) {
    FunctionHandle_t hFunction = { 0 };
    FunctionType_t type = kFunctionTypeAND;
    int32_t ret = 0;

    function_set_type(&hFunction, kFunctionTypeOR);
    function_init(&hFunction);
    ret = function_set_type(&hFunction, type);
    function_get_type(&hFunction, &type);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INITIALIZED, ret);
    TEST_ASSERT_EQUAL(kFunctionTypeOR, type);
}
