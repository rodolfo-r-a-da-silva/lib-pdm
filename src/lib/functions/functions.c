/**
 * @file functions.c
 * @brief Implementation of the functions library
 * 
 * @author Rodolfo R. A. da Silva
 * @date 2024-06-12
 */

#include "functions.h"

#include <stddef.h>
#include <stdio.h>

/**
 * @section Private Functions
 */

/**
 * @brief Check if the input number is valid for the configured function type
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input to be validated
 * 
 * @return Zero if valid, an error code if negative
 * @retval LIB_PDM_ERROR_NONE The input number is valid
 * @retval LIB_PDM_ERROR_WRONG_PARAM The function instance is NULL or the input number is invalid
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The instanc's function tyoe is not supported
 */
static int32_t input_valid(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr) {
    int32_t ret = LIB_PDM_ERROR_WRONG_PARAM;

    if (instance != NULL) {
        switch (instance->type) {
            case kFunctionTypeNOT:
            case kFunctionTypePulse:
                if (input_nbr == 0U) {
                    ret = LIB_PDM_ERROR_NONE;
                }
                break;

            case kFunctionTypeAND:
            case kFunctionTypeOR:
            case kFunctionTypeXOR:
            case kFunctionTypeMask:
            case kFunctionTypeEq:
            case kFunctionTypeLt:
            case kFunctionTypeMt:
                if (input_nbr < 2U) {
                    ret = LIB_PDM_ERROR_NONE;
                }
                break;

            default:
                ret = LIB_PDM_ERROR_FUNCTION_TYPE;
                break;
        }
    }

    return ret;
}

/**
 * @brief Set an input pointer of a function
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input which the pointer is to be retrieved
 * 
 * @return A pointer to the the function's input
 */
static int32_t* get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr) {
    int32_t* ret = NULL;

    switch (instance->type) {
        case kFunctionTypeNOT:
        case kFunctionTypePulse:
            ret = instance->input[0];
            break;

        case kFunctionTypeAND:
        case kFunctionTypeOR:
        case kFunctionTypeXOR:
        case kFunctionTypeMask:
        case kFunctionTypeEq:
        case kFunctionTypeLt:
        case kFunctionTypeMt:
            ret = instance->input[input_nbr];
            break;

        default:
            break;
    }

    return ret;
}

/**
 * @brief Set an input pointer of a function
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input which the pointer is to be set
 * @param[in] input The pointer to the variable to be set as input
 */
static void set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* input) {
    switch (instance->type) {
        case kFunctionTypeNOT:
        case kFunctionTypePulse:
            instance->input[0] = input;
            break;

        case kFunctionTypeAND:
        case kFunctionTypeOR:
        case kFunctionTypeXOR:
        case kFunctionTypeMask:
        case kFunctionTypeEq:
        case kFunctionTypeLt:
        case kFunctionTypeMt:
            instance->input[input_nbr] = input;
            break;

        default:
            break;
    }
}

/**
 * @brief Check if the function has its required inputs set for its type
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return Inform if the inputs are all set for the current function type
 * @retval true The required inputs are set for the current function type
 * @retval false The required inputs are not set for the current function type
 */
static bool are_inputs_set(FunctionHandle_t* instance) {
    bool ret = true;

    switch (instance->type) {
        case kFunctionTypeNOT:
        case kFunctionTypePulse: {
            if (instance->input[0] == NULL) { ret = false; }
            break;
        }
        
        case kFunctionTypeAND:
        case kFunctionTypeOR:
        case kFunctionTypeXOR:
        case kFunctionTypeMask:
        case kFunctionTypeEq:
        case kFunctionTypeLt:
        case kFunctionTypeMt: {
            for (size_t i = 0U; i < LIB_PDM_FUNCTION_TWO_INPUTS; ++i) {
                if (instance->input[i] == NULL) {
                    ret = false;
                    break;
                }
            }

            break;
        }

        default:
            ret = false;
            break;
    }

    return ret;
}

/**
 * @brief Check if the current function type can have input edges set
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return The validity of the input edges for the current function type
 * @retval true The current function type can have input edges configured
 * @retval false The current function type can't have input edges configured
 */
static bool has_input_edges(FunctionHandle_t* instance) {
    return ((instance->type >= kFunctionTypePulse)
            && (instance->type < kFunctionTypeMax));
}

/**
 * @brief Calculate the function's result based on its type and inputs
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return The result of the function's calculation
 */
static int32_t calculate_output(FunctionHandle_t* instance) {
    int32_t ret = LIB_PDM_FUNCTION_FALSE;

    switch (instance->type) {
        case kFunctionTypeNOT:
            ret = (*instance->input[0] != LIB_PDM_FUNCTION_FALSE) 
                ? LIB_PDM_FUNCTION_FALSE : LIB_PDM_FUNCTION_TRUE;
            break;

        case kFunctionTypeAND:
            ret = ((*instance->input[0] != LIB_PDM_FUNCTION_FALSE)
                    && (*instance->input[1] != LIB_PDM_FUNCTION_FALSE))
                ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        case kFunctionTypeOR:
            ret = ((*instance->input[0] != LIB_PDM_FUNCTION_FALSE)
                    || (*instance->input[1] != LIB_PDM_FUNCTION_FALSE))
                ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        case kFunctionTypeXOR:
            ret = (((*instance->input[0] == LIB_PDM_FUNCTION_FALSE)
                    && (*instance->input[1] == LIB_PDM_FUNCTION_FALSE))
                    ||((*instance->input[0] != LIB_PDM_FUNCTION_FALSE)
                    && (*instance->input[1] != LIB_PDM_FUNCTION_FALSE)))
                ? LIB_PDM_FUNCTION_FALSE : LIB_PDM_FUNCTION_TRUE;
            break;

        case kFunctionTypeMask:
            ret = (int32_t) (((uint32_t) *instance->input[0])
                    & ((uint32_t) *instance->input[1]));
            break;

        case kFunctionTypeEq:
            ret = (*instance->input[0] == *instance->input[1])
                ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        case kFunctionTypeLt:
            ret = (*instance->input[0] < *instance->input[1])
                ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        case kFunctionTypeMt:
            ret = (*instance->input[0] > *instance->input[1])
                ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        default:
            break;
    }

    return ret;
}

/** 
 * @section Public Functions 
 */

int32_t function_init(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else if (!are_inputs_set(instance)) {
        return LIB_PDM_ERROR_NO_INPUT;
    }

    instance->output[kFunctionOutPrevious] = 0;
    instance->output[kFunctionOutCurrent] = 0;
    instance->output[kFunctionOutNext] = 0;
    instance->is_init = true;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_deinit(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    instance->is_init = false;

    return LIB_PDM_ERROR_NONE;
}

bool function_is_init(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return false;
    }

    return instance->is_init;
}

int32_t function_run(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else if (!function_is_init(instance)) {
        return LIB_PDM_ERROR_NO_INIT;
    }

    instance->output[kFunctionOutPrevious] = instance->output[kFunctionOutCurrent];
    instance->output[kFunctionOutNext] = calculate_output(instance);
    instance->output[kFunctionOutCurrent] = instance->output[kFunctionOutNext];

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_result(FunctionHandle_t* instance, int32_t* result) {
    if ((instance == NULL) || (result == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *result = instance->output[kFunctionOutCurrent];

    return LIB_PDM_ERROR_NONE;
}

int32_t function_get_result_inversion(FunctionHandle_t* instance, bool* invert) {
    if ((instance == NULL) || (invert == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else {
        // Do nothing
    }

    *invert = instance->invert;

    return LIB_PDM_ERROR_NONE;
}

int32_t function_set_result_inversion(FunctionHandle_t* instance, bool invert) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else {
        // Do nothing
    }

    instance->invert = invert;

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
    int32_t ret = input_valid(instance, input_nbr);

    if (p_input == NULL) {
        ret = LIB_PDM_ERROR_WRONG_PARAM;
    }

    if (ret == LIB_PDM_ERROR_NONE) {
        *p_input = get_input(instance, input_nbr);
    }

    return ret;
}

int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input) {
    int32_t ret = input_valid(instance, input_nbr);

    if (p_input == NULL) {
        ret = LIB_PDM_ERROR_WRONG_PARAM;
    }

    if (ret == LIB_PDM_ERROR_NONE) {
        set_input(instance, input_nbr, p_input);
    }

    return ret;
}

int32_t function_get_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t* p_edge) {
    int32_t ret = input_valid(instance, input_nbr);

    if (p_edge == NULL) {
        ret = LIB_PDM_ERROR_WRONG_PARAM;
    }

    if ((ret == LIB_PDM_ERROR_NONE) && !has_input_edges(instance)) {
        ret = LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    if (ret == LIB_PDM_ERROR_NONE) {
        *p_edge = instance->edge;
    }

    return ret;
}

int32_t function_set_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t edge) {
    int32_t ret = input_valid(instance, input_nbr);

    if ((ret == LIB_PDM_ERROR_NONE) && !has_input_edges(instance)) {
        ret = LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    if ((ret == LIB_PDM_ERROR_NONE) && (edge >= kFunctionInputEdgeMax)) {
        ret = LIB_PDM_ERROR_WRONG_PARAM;
    }

    if (ret == LIB_PDM_ERROR_NONE) {
        instance->edge = edge;
    }

    return ret;
}
