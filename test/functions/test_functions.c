#include "unity.h"

#include "functions.h"

void test_whenInitWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_init(NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenDeInitWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_deinit(NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetIsInitWithNullInstance_thenReturnFalse(void) {
    bool is_init = true;

    is_init = function_is_init(NULL);

    TEST_ASSERT_EQUAL(false, is_init);
}

void test_whenRunWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_run(NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetResultWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    FunctionHandle_t function = { 0 };

    ret = function_get_result(&function, NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetResultWithNullResult_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    int32_t result = 0;

    ret = function_get_result(NULL, &result);

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

void test_whenSetTypeWithNullInstance_thenReturnWrontParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_set_type(NULL, kFunctionTypeNone);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetAndGetType_thenReturnNoErrorWhenNotInit(void) {
    FunctionHandle_t function = { 0 };
    FunctionType_t type = kFunctionTypeNone;

    function_set_type(&function, kFunctionTypeNOT);
    function_get_type(&function, &type);

    TEST_ASSERT_EQUAL(kFunctionTypeNOT, type);
}

void test_whenGetInputWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    int32_t input = 0;
    int32_t* p_input = &input;

    ret = function_get_input(NULL, 0, &p_input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetInputWithNullInput_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    FunctionHandle_t function = { 0 };

    ret = function_get_input(&function, 0, NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetInputWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    int32_t input = 0;

    ret = function_set_input(NULL, 0, &input);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetInputWithNullInput_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    FunctionHandle_t function = { 0 };

    ret = function_set_input(&function, 0, NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetAndGetInput_thenReturnNoErrorWhenNotInit(void) {
    FunctionHandle_t function = { .type = kFunctionTypeNOT };
    int32_t input = 0;
    int32_t* p_input = NULL;

    function_set_input(&function, 0, &input);
    function_get_input(&function, 0, &p_input);

    TEST_ASSERT_EQUAL(&input, p_input);
}

void test_whenGetResultinversionWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    bool inverted = false;

    ret = function_get_result_inversion(NULL, &inverted);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenGetResultinversionWithNullinversion_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;
    FunctionHandle_t function = { 0 };

    ret = function_get_result_inversion(&function, NULL);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetResultinversionWithNullInstance_thenReturnWrongParamError(void) {
    int32_t ret = LIB_PDM_ERROR_NONE;

    ret = function_set_result_inversion(NULL, true);

    TEST_ASSERT_EQUAL(LIB_PDM_ERROR_WRONG_PARAM, ret);
}

void test_whenSetAndGetResultinversion_thenReturnNoErrorWhenNotInit(void) {
    FunctionHandle_t function = { .type = kFunctionTypeNOT };
    bool inverted = false;

    function_set_result_inversion(&function, true);
    function_get_result_inversion(&function, &inverted);

    TEST_ASSERT_EQUAL(true, inverted);
}
