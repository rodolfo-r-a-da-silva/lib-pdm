#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {}

void test_whenSetAndGetType_thenReturnsNoErrorWhenNotInit(void) {
    FunctionHandle_t function;
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&function, kFunctionTypeNOT);
    function_get_type(&function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_whenSetNotFunctionInput1_thenReturnsWrongParamError(void) {
    FunctionHandle_t function;
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetNotFunctionInput0_thenReturnsNoError(void) {
    FunctionHandle_t function;
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}
