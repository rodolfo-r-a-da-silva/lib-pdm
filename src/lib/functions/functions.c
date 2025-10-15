#include <stddef.h>

#include "functions.h"

static bool is_input_valid(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr);
static bool are_inputs_set(FunctionHandle_t* instance);

int32_t function_init(FunctionHandle_t* instance) {
    if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else if (!are_inputs_set(instance)) {
        return LIB_PDM_ERROR_NO_INPUT;
    }

    instance->output = 0;
    instance->is_init = true;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_deinit(FunctionHandle_t* instance) {
    if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    instance->is_init = false;

    return LIB_PDM_ERROR_NONE;
}

bool function_is_init(FunctionHandle_t* instance) {
    return instance->is_init;
}

int32_t function_run(FunctionHandle_t* instance) {
    if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_result(FunctionHandle_t* instance, int32_t* result) {
    *result = instance->output;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type) {
    if ((instance == NULL) || (type == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *type = instance->type;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    instance->type = type;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t** p_input) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *p_input = instance->data_not.input;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    instance->data_not.input = p_input;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t* p_edge) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    return LIB_PDM_ERROR_NONE;
}
int32_t function_set_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t edge) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    return LIB_PDM_ERROR_NONE;
}

static bool is_input_valid(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr) {
    if (instance == NULL) {
        return false;
    }

    bool ret = false;

    switch (input_nbr) {
        case 0U:
            ret = (instance->type == kFunctionTypeNOT);
            break;

        default:
            break;
    }

    return ret;
}

static bool are_inputs_set(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return false;
    }

    bool ret = false;

    switch (instance->type) {
        case kFunctionTypeNOT: {
            if (instance->data_not.input != NULL) {
                ret = true;
            }
        }

        default:
            break;
    }

    return ret;
}
