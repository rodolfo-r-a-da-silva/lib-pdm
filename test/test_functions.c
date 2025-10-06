#include "unity.h"

#include "functions.h"

void setUp(void) {}
void tearDown(void) {}

// Instance is initialized with zeroed output


void test_Function_InstanceInitializedWithZeroedOutput(void) {
    int32_t result = -1;

    function_init(0U);
    function_get_result(0U, &result);

    TEST_ASSERT_EQUAL(0, result);
}
