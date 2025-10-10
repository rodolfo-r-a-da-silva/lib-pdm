#include <string.h>

#include "unity.h"

#include "functions.h"

static FunctionHandle_t h_function;

void setUp(void) {
    memset(&h_function, 0, sizeof(h_function));
}

void tearDown(void) {
    memset(&h_function, 0, sizeof(h_function));
}

void test_GetAndSetType_ReturnsNoErrorWhenNotInit(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&h_function, kFunctionTypeNOT);
    function_get_type(&h_function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_InitWhenTypeIsNotNone_ReturnsNoError(void) {
    int32_t ret = 0;

    function_set_type(&h_function, kFunctionTypeNOT);
    ret = function_init(&h_function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_InitWhenTypeIsNone_ReturnsTypeError(void) {
    int32_t ret = function_init(&h_function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INIT_TYPE, ret);
}

void test_InitDoesNotChangeChangeType(void) {
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&h_function, kFunctionTypeNOT);
    function_init(&h_function);
    function_get_type(&h_function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_DeinitDoesNotChangeType(void) {
    FunctionType_t type = kFunctionTypeNOT;

    function_set_type(&h_function, kFunctionTypeNOT);
    function_init(&h_function);
    function_deinit(&h_function);
    function_get_type(&h_function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_ChangeTypeWhenInitialized_ReturnsErrorAndKeepsType(void) {
    FunctionType_t type = kFunctionTypeNOT;
    int32_t ret = 0;

    function_set_type(&h_function, kFunctionTypeOR);
    function_init(&h_function);
    ret = function_set_type(&h_function, type);
    function_get_type(&h_function, &type);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_INITIALIZED, ret);
    TEST_ASSERT_EQUAL(kFunctionTypeOR, type);
}

void test_InitSetsStateToInitialized(void) {
    bool initialized = false;

    function_set_type(&h_function, kFunctionTypeNOT);
    function_init(&h_function);
    initialized = function_is_init(&h_function);

    TEST_ASSERT_EQUAL(true, initialized);
}

void test_DeinitSetsStateToNotInitialized(void) {
    bool initialized = true;

    function_set_type(&h_function, kFunctionTypeNOT);
    function_init(&h_function);
    function_deinit(&h_function);
    initialized = function_is_init(&h_function);

    TEST_ASSERT_EQUAL(false, initialized);
}
