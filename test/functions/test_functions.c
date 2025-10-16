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

void test_whenNoneFunctionSetInput0Edge_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_set_input_edge(&function, 0U, kFunctionInputEdgeBoth);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenNoneFunctionGetInput0Edge_thenReturnWrongParamError(void) {
    FunctionHandle_t function = { 0 };
    FunctionInputEdge_t* edge = kFunctionInputEdgeNone;
    int32_t ret = 0;

    function_set_type(&function, kFunctionTypeNone);
    ret = function_get_input_edge(&function, 0U, &edge);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
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
