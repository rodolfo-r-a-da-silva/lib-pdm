#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {}

void test_whenSetTypeWithNullInstance_thenReturnWrontParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_set_type(NULL, kFunctionTypeNone);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetTypeWithNullInstance_thenReturnWrontParamError(void) {
    FunctionType_t type = kFunctionTypeNone;
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_get_type(NULL, &type);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetTypeWithNullType_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    ret = function_get_type(&function, NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetAndGetType_thenReturnNoErrorWhenNotInit(void) {
    FunctionHandle_t function = { 0 };
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&function, kFunctionTypeNOT);
    function_get_type(&function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_whenNoneFunctionSetInput0_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNoneFunctionGetInput0_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* input = NULL;
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_get_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNotFunctionSetInput1_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNotFunctionSetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}
