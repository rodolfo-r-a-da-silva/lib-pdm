#include "unity.h"

#include "functions.h"

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

void test_whenNoneFunctionSetInput0Edge_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeBoth);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNoneFunctionGetInput0Edge_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t edge = kFunctionInputEdgeNone;
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNoneFunctionSetInvertedResult_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_set_result_invertion(&function, false);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNoneFunctionGetInvertedResult_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    bool inverted = true;
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_get_result_invertion(&function, &inverted);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
    TEST_ASSERT_EQUAL(true, inverted);
}

void test_whenNoneFunctionInit_thenReturnTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNoneFunctionDeinit_thenReturnTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_deinit(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNoneFunctionRun_thenReturnTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNotFunctionSetInput1_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}
