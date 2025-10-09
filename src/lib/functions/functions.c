#include "functions.h"

static struct {
    int32_t output;
    FunctionType_t type;
    bool initialized;
} function_ctx;

int32_t function_init(FunctionInstance_t instance) {
    if (function_ctx.type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_INIT_TYPE;
    }

    function_ctx.output = 0;
    function_ctx.initialized = true;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_deinit(FunctionInstance_t instance) {
    function_ctx.type = kFunctionTypeNone;

    return 0;
}

int32_t function_get_result(FunctionInstance_t instance, int32_t* result) {
    *result = function_ctx.output;

    return 0;
}

int32_t function_get_type(FunctionInstance_t instance, FunctionType_t* type) {
    *type = function_ctx.type;

    return 0;
}

int32_t function_set_type(FunctionInstance_t instance, FunctionType_t type) {
    if (function_ctx.initialized) {
        return LIB_PDM_ERROR_INITIALIZED;
    }

    function_ctx.type = type;

    return 0;
}
