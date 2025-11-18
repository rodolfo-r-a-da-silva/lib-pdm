#include "unity.h"

#include "functions.h"

void test_whenBitwiseAndFunctionSetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionSetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionSetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_set_input(&function, 2U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenBitwiseAndFunctionGetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionGetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_get_input(&function, 1U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionGetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_get_input(&function, 2U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenBitwiseAndFunctionSetInput_thenGetInputRetrievesAddress(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t* p_input = NULL;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 0U, &input);
    function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(&input, p_input);
}

void test_whenBitwiseAndFunctionSetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeBoth);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenBitwiseAndFunctionGetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t edge = kFunctionInputEdgeBoth;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenBitwiseAndFunctionSetInvertedResultWithTrue_thenReturnErrorNone(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_set_result_invertion(&function, true);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion(void) {
    FunctionHandle_t function = { 0 };
    bool invert = false;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_result_invertion(&function, true);
    ret = function_get_result_invertion(&function, &invert);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
    TEST_ASSERT_EQUAL(true, invert);
}

void test_whenBitwiseAndFunctionInitWithoutInputs_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenBitwiseAndFunctionInitWithoutInput0_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 1U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenBitwiseAndFunctionInitWithoutInput1_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 0U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenBitwiseAndFunctionInitWithBothInputs_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenBitwiseAndFunctionRunWithoutInit_thenReturnInitError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INIT, ret);
}

void test_whenBitwiseAndFunctionRun_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeBitwiseAND);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}
