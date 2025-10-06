#include "functions.h"

static struct {
    int32_t output;
} function_instances;

int32_t function_init(FunctionInstance_t instance) {
    function_instances.output = 0;

    return 0;
}

int32_t function_get_result(FunctionInstance_t instance, int32_t* result) {
    *result = function_instances.output;

    return 0;
}
