#include "functions.h"

int32_t function_init(FunctionHandle_t* instance) {
    if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_INIT_TYPE;
    }

    instance->output = 0;
    instance->is_init = true;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_deinit(FunctionHandle_t* instance) {
    instance->is_init = false;

    return 0;
}

bool function_is_init(FunctionHandle_t* instance) {
    return instance->is_init;
}

int32_t function_get_result(FunctionHandle_t* instance, int32_t* result) {
    *result = instance->output;

    return 0;
}

int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type) {
    *type = instance->type;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type) {
    if (instance->is_init) {
        return LIB_PDM_ERROR_INITIALIZED;
    }

    instance->type = type;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input) {
    return LIB_PDM_ERROR_NONE;
}

int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input) {
    if (input_nbr > 0U) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    return LIB_PDM_ERROR_NONE;
}
