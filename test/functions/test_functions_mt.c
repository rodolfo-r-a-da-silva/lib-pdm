#include "unity.h"

#include "functions.h"

void test_whenMtFunctionSetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionSetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionSetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_set_input(&function, 2U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenMtFunctionGetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionGetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_get_input(&function, 1U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionGetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_get_input(&function, 2U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenMtFunctionSetInput_thenGetInputRetrievesAddress(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t* p_input = NULL;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &input);
    function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(&input, p_input);
}

void test_whenMtFunctionSetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeBoth);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenMtFunctionGetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t edge = kFunctionInputEdgeBoth;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenMtFunctionSetInvertedResultWithTrue_thenReturnErrorNone(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_set_result_invertion(&function, true);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion(void) {
    FunctionHandle_t function = { 0 };
    bool invert = false;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_result_invertion(&function, true);
    ret = function_get_result_invertion(&function, &invert);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
    TEST_ASSERT_EQUAL(true, invert);
}

void test_whenMtFunctionInitWithoutInputs_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMtFunctionInitWithoutInput0_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 1U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMtFunctionInitWithoutInput1_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMtFunctionInitWithBothInputs_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionRunWithoutInit_thenReturnInitError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INIT, ret);
}

void test_whenMtFunctionRun_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMtFunctionInput0And1Are0_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0, 0 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0Is0And1Is1_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0, 1 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0Is1And1Is0_thenResultIsTrue(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 1, 0 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_TRUE, output);
}

void test_whenMtFunctionInput0And1Are1_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 1, 1 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0Is1And1Is2_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 1, 2 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0Is2And1Is1_thenResultIsTrue(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 2, 1 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_TRUE, output);
}

void test_whenMtFunctionInput0And1Are2_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 2, 2 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0Is0And1IsMinus1_thenResultIsFTrue(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0, -1 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_TRUE, output);
}

void test_whenMtFunctionInput0IsMinus1And1Is0_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { -1, 0 };
    int32_t output = LIB_PDM_FUNCTION_FALSE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}

void test_whenMtFunctionInput0And1AreMinus1_thenResultIsFalse(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { -1, -1 };
    int32_t output = LIB_PDM_FUNCTION_TRUE;

    function_set_type(&function, kFunctionTypeMt);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    function_run(&function);

    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(LIB_PDM_FUNCTION_FALSE, output);
}
