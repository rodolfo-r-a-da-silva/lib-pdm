#include <stddef.h>

#include "functions.h"

static bool get_result_inversion(FunctionHandle_t* instance);
static void set_output_inversion(FunctionHandle_t* instance, bool invert);
static bool is_input_valid(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr);
static bool has_input_edges(FunctionHandle_t* instance);
static bool are_inputs_set(FunctionHandle_t* instance);

/**
 * @brief Initializes the function instance
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 */
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

/**
 * @brief Deinitializes the function instance
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 */
int32_t function_deinit(FunctionHandle_t* instance) {
    if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    instance->is_init = false;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Check if the function instance is initialized
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return True if the function is initialized, false if not initialized
 */
bool function_is_init(FunctionHandle_t* instance) {
    return instance->is_init;
}

/**
 * @brief Process the function's logic
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 */
int32_t function_run(FunctionHandle_t* instance) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else if (!function_is_init(instance)) {
        return LIB_PDM_ERROR_NO_INIT;
    }

    switch (instance->type) {
        case kFunctionTypeNOT:
            instance->output = (*instance->data_not.input == LIB_PDM_FUNCTION_FALSE) 
                    ? LIB_PDM_FUNCTION_TRUE : LIB_PDM_FUNCTION_FALSE;
            break;

        default:
            break;
    }

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Get the function's result from the last process execution
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param result A pointer to the variable that stores the function's result
 * 
 * @return An error code if negative
 */
int32_t function_get_result(FunctionHandle_t* instance, int32_t* result) {
    if ((instance == NULL) || (result == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *result = instance->output;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Check if the function's output logic is inverted
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param invert A pointer to the variable that stores the functoin logic
 * inversion
 * 
 * @return An error code if negative
 */
int32_t function_get_result_invertion(FunctionHandle_t* instance, bool* invert) {
    if ((instance == NULL) || (invert == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else {
        // Do nothing
    }

    *invert = get_result_inversion(instance);

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Set the function's logic inversion
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param invert False if the function's result must stay as is, false if the
 * function's result must be inverted. When inverted, any result different from
 * 0 will turn to false and 0 will turn to true
 * 
 * @return An error code if negative
 */
int32_t function_set_result_invertion(FunctionHandle_t* instance, bool invert) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (instance->type == kFunctionTypeNone) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    } else {
        // Do nothing
    }

    set_output_inversion(instance, invert);

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Get the function's logic type
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param type A pointer to the variable that stores the function's logic type
 * 
 * @return An error code if negative
 */
int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type) {
    if ((instance == NULL) || (type == NULL)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *type = instance->type;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Set the function's logic type
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param type The function type to be set
 * 
 * @return An error code if negative
 */
int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type) {
    if (instance == NULL) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    instance->type = type;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Get the function's input memory address
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param input_nbr The number of the input address to be retrived
 * @param p_input A pointer to store the address of the retrieved input channel
 * 
 * @return An error code if negative
 */
int32_t function_get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t** p_input) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    *p_input = instance->data_not.input;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Set the function's input memory address
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param input_nbr The number of the input address to be set
 * @param p_input A pointer with the address of the input channel
 * 
 * @return An error code if negative
 */
int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    }

    instance->data_not.input = p_input;

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Get the function's input edge type
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param input_nbr The number of the input edge type to be retrieved
 * @param p_input A pointer to store the retrieved input edge type
 * 
 * @return An error code if negative
 */
int32_t function_get_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t* p_edge) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (!has_input_edges(instance)) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Set the function's input edge type
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param input_nbr The number of the input edge type to be set
 * @param p_input The input edge type to be set
 * 
 * @return An error code if negative
 */
int32_t function_set_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t edge) {
    if (!is_input_valid(instance, input_nbr)) {
        return LIB_PDM_ERROR_WRONG_PARAM;
    } else if (!has_input_edges(instance)) {
        return LIB_PDM_ERROR_FUNCTION_TYPE;
    }

    return LIB_PDM_ERROR_NONE;
}

/**
 * @brief Get the function's result invertion from the specific struct
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return Result inversion variable value
 */
static bool get_result_inversion(FunctionHandle_t* instance) {
    switch (instance->type) {
        case kFunctionTypeNOT: {
            return instance->data_not.invert;
        }

        default: {
            break;
        }
    }

    return false;
}

/**
 * @brief Set the function's result invertion in the specific struct
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param invert The function's result invertion value
 */
static void set_output_inversion(FunctionHandle_t* instance, bool invert) {
    switch (instance->type) {
        case kFunctionTypeNOT: {
            instance->data_not.invert = invert;
            break;
        }

        default: {
            break;
        }
    }

    return;
}

/**
 * @brief Check if the input number is valid for the configured function type
 * 
 * @param instance A pointer to the struct containing the function's data
 * @param input_nbr The number of the input to be validated
 * 
 * @return True if the input number is valid for the current function type,
 * false if invalid
 */
static bool is_input_valid(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr) {
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

/**
 * @brief Check if the current function type can have input edges set
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return True if the current function type can have input edges configured,
 * false if it can't
 */
static bool has_input_edges(FunctionHandle_t* instance) {
    return (instance->type != kFunctionTypeNOT);
}

/**
 * @brief Check if the function has its required inputs set for its type
 * 
 * @param instance A pointer to the struct containing the function's data
 * 
 * @return True if the required inputs are set, false if aren't set
 */
static bool are_inputs_set(FunctionHandle_t* instance) {
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
