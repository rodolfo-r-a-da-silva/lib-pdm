#include "unity.h"

#include "functions.h"

void test_whenMaskFunctionSetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_set_input(&function, 0U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionSetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_set_input(&function, 1U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionSetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_set_input(&function, 2U, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenMaskFunctionGetInput0_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionGetInput1_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = NULL;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_get_input(&function, 1U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionGetInput2_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t* p_input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_get_input(&function, 2U, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenMaskFunctionSetInput_thenGetInputRetrievesAddress(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t* p_input = NULL;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, &input);
    function_get_input(&function, 0U, &p_input);

    TEST_ASSERT_EQUAL(&input, p_input);
}

void test_whenMaskFunctionSetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeBoth);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenMaskFunctionGetInpuEdge0_thenReturnFunctionTypeError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t edge = kFunctionInputEdgeBoth;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_FUNCTION_TYPE, ret);
}

void test_whenMaskFunctionSetInvertedResultWithTrue_thenReturnErrorNone(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_set_result_invertion(&function, true);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion(void) {
    FunctionHandle_t function = { 0 };
    bool invert = false;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_result_invertion(&function, true);
    ret = function_get_result_invertion(&function, &invert);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
    TEST_ASSERT_EQUAL(true, invert);
}

void test_whenMaskFunctionInitWithoutInputs_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMaskFunctionInitWithoutInput0_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 1U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMaskFunctionInitWithoutInput1_thenReturnInputError(void) {
    FunctionHandle_t function = { 0 };
    int32_t input = 0;
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, &input);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INPUT, ret);
}

void test_whenMaskFunctionInitWithBothInputs_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_init(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionRunWithoutInit_thenReturnInitError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NO_INIT, ret);
}

void test_whenMaskFunctionRun_thenReturnNoError(void) {
    FunctionHandle_t function = { 0 };
    int32_t inputs[2] = { 0 };
    int32_t ret = LIB_PDM_ERROR_NONE;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, &inputs[0]);
    function_set_input(&function, 1U, &inputs[1]);
    function_init(&function);
    ret = function_run(&function);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_NONE, ret);
}

void test_whenMaskFunctionInput0Is0x00AndInput1Is0xff_thenResultIs0x00(void) {
    FunctionHandle_t function = { 0 };
    uint32_t inputs[2] = { 0x00, 0xFF };
    uint32_t output = 0x00;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, (int32_t*) &inputs[0]);
    function_set_input(&function, 1U, (int32_t*) &inputs[1]);
    function_init(&function);
    function_run(&function);
    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(0x00, output);
}

void test_whenMaskFunctionInput0Is0xffAndInput1Is0x00_thenResultIs0x00(void) {
    FunctionHandle_t function = { 0 };
    uint32_t inputs[2] = { 0x00, 0xFF };
    uint32_t output = 0xFF;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, (int32_t*) &inputs[0]);
    function_set_input(&function, 1U, (int32_t*) &inputs[1]);
    function_init(&function);
    function_run(&function);
    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(0x00, output);
}

void test_whenMaskFunctionInput0Is0x11AndInput1Is0xff_thenResultIs0x11(void) {
    FunctionHandle_t function = { 0 };
    uint32_t inputs[2] = { 0x11, 0xFF };
    uint32_t output = 0xFF;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, (int32_t*) &inputs[0]);
    function_set_input(&function, 1U, (int32_t*) &inputs[1]);
    function_init(&function);
    function_run(&function);
    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(0x11, output);
}

void test_whenMaskFunctionInput0Is0xffAndInput1Is0x11_thenResultIs0x11(void) {
    FunctionHandle_t function = { 0 };
    uint32_t inputs[2] = { 0xFF, 0x11 };
    uint32_t output = 0xFF;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, (int32_t*) &inputs[0]);
    function_set_input(&function, 1U, (int32_t*) &inputs[1]);
    function_init(&function);
    function_run(&function);
    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(0x11, output);
}

void test_whenMaskFunctionInput0Is0xffffffffAndInput1Is0x0000ffff_thenResultIs0x0000ffff(void) {
    FunctionHandle_t function = { 0 };
    uint32_t inputs[2] = { 0xFFFFFFFF, 0x0000FFFF };
    uint32_t output = 0xFF;

    function_set_type(&function, kFunctionTypeMask);
    function_set_input(&function, 0U, (int32_t*) &inputs[0]);
    function_set_input(&function, 1U, (int32_t*) &inputs[1]);
    function_init(&function);
    function_run(&function);
    function_get_result(&function, &output);

    TEST_ASSERT_EQUAL(0x0000FFFF, output);
}
