#include "unity.h"

#include "functions.h"

void test_whenNotFunctionSetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenNotFunctionGetInput1_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_get_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNotFunctionGetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_get_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenNotFunctionSetInput_thenGetInputRetrievesAddress(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t* address = NULL;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    function_get_input(&function, 0U, &address);

    TEST_ASSERT_EQUAL_HEX32(&input, address);
}

void test_whenNotFunctionSetInput0Edge_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeRising);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNotFunctionGetInput0Edge_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t edge = kFunctionInputEdgeNone;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenNotFunctionSetInvertedResultWithTrue_thenReturnErrorNone(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_set_result_invertion(&function, true);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenNotFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion(void) {
    FunctionHandle_t function = { 0 };
    bool invert = false;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_result_invertion(&function, true);
    ret = function_get_result_invertion(&function, &invert);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
    TEST_ASSERT_EQUAL(true, invert);
}

void test_whenNotFunctionInitWithoutInputs_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenNotFunctionInitWithInputs_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenNotInitialized_thenIsInitReturnsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    bool ret = false;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    ret = function_is_init(&function);

    TEST_ASSERT_EQUAL(false, ret);
}

void test_whenInitialized_thenIsInitReturnsTrue(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    bool ret = false;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    function_init(&function);
    ret = function_is_init(&function);

    TEST_ASSERT_EQUAL(true, ret);
}

void test_whenNotFunctionRunWithoutInit_thenReturnInitError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INIT, ret);
}

void test_whenNotFunctionRun_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    function_init(&function);

    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenNotFunctionInputIsFalse_thenResultIsTrue(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = LIB_PDM_FUNCTION_FALSE;
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_TRUE, output);
}

void test_whenNotFunctionInputIsTrue_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = LIB_PDM_FUNCTION_TRUE;
    int32_t output = LIB_PDM_FUNCTION_TRUE;

    function_set_type(&function, kFunctionTypeNOT);
    function_set_input(&function, 0U, &input);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}
