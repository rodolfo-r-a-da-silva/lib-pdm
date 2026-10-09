/**
 * @file functions.h
 * @brief Header file for the functions library
 * 
 * This file contains the declarations of the functions and data structures used in the functions library.
 * It provides an interface for initializing, deinitializing, running, and managing function instances.
 * 
 * @author Rodolfo R. A. da Silva
 * @date 2024-06-12
 */

#ifndef LIB_FUNCTIONS_FUNCTIONS_H_
#define LIB_FUNCTIONS_FUNCTIONS_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/pdm_errno.h"

#define LIB_PDM_FUNCTION_FALSE  0
#define LIB_PDM_FUNCTION_TRUE  1

#define LIB_PDM_FUNCTION_NOT_INPUTS  1U
#define LIB_PDM_FUNCTION_TWO_INPUTS  2U
#define LIB_PDM_FUNCTION_AND_INPUTS  LIB_PDM_FUNCTION_TWO_INPUTS
#define LIB_PDM_FUNCTION_OR_INPUTS  LIB_PDM_FUNCTION_TWO_INPUTS
#define LIB_PDM_FUNCTION_XOR_INPUTS  LIB_PDM_FUNCTION_TWO_INPUTS
#define LIB_PDM_FUNCTION_MASK_INPUTS  LIB_PDM_FUNCTION_TWO_INPUTS

typedef enum {
    kFunctionTypeNone = 0U,
    kFunctionTypeNOT,
    kFunctionTypeAND,
    kFunctionTypeOR,
    kFunctionTypeXOR,
    kFunctionTypeMask,
    kFunctionTypeEq,
    kFunctionTypeLt,
    kFunctionTypeMt,
    kFunctionTypeHysteresis,
    kFunctionTypeBlink,
    kFunctionTypePulse,
    kFunctionTypeSet,
    kFunctionTypeReset,
    kFunctionTypeToggle,
    kFunctionTypeCounter,

    kFunctionTypeMax
} FunctionType_t;

typedef enum {
    kFunctionInputEdgeNone = 0U,
    kFunctionInputEdgeFalling,
    kFunctionInputEdgeRising,
    kFunctionInputEdgeBoth,

    kFunctionInputEdgeMax
} FunctionInputEdge_t;

typedef uint8_t FunctionInputNbr_t;

typedef struct {
    int32_t output;
    FunctionType_t type;
    bool is_init;

    bool invert;
    int32_t* input[2];
} FunctionHandle_t;

/**
 * @brief Initialize the function instance
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function was initialized successfully
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The function type is not set
 * @retval LIB_PDM_ERROR_NO_INPUT The function's required inputs are not set
 */
int32_t function_init(FunctionHandle_t* instance);

/**
 * @brief Deinitializes the function instance
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function was deinitialized successfully
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The function type is not set
 */
int32_t function_deinit(FunctionHandle_t* instance);

/**
 * @brief Check if the function instance is initialized
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return true if the function is initialized, false otherwise
 * @retval true The function is initialized
 * @retval false The function is not initialized
 */
bool function_is_init(FunctionHandle_t* instance);

/**
 * @brief Process the function's logic
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function was processed successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM The function instance is NULL
 * @retval LIB_PDM_ERROR_NO_INIT The function instance is not initialized
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The function type is not set
 */
int32_t function_run(FunctionHandle_t* instance);

/**
 * @brief Get the function's result
 * 
 * @param[in]  instance A pointer to the struct containing the function's data
 * @param[out] result A pointer to the variable that stores the function's result
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's result was retrieved successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL
 */
int32_t function_get_result(FunctionHandle_t* instance, int32_t* result);

/**
 * @brief Check if the function's output logic is inverted
 * 
 * @param[in]  instance A pointer to the struct containing the function's data
 * @param[out] invert A pointer to the variable that stores the functoin logic inversion
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's output inversion was retrieved successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The function type is not set
 */
int32_t function_get_result_inversion(FunctionHandle_t* instance, bool* invert);

/**
 * @brief Set the function's logic inversion
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] invert False if the function's result must stay as is, false if the function's result must be inverted.
 *                   When inverted, any result different from 0 will turn to false and 0 will turn to true
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's output inversion was set successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM The function instance is NULL
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The function type is not set
 */
int32_t function_set_result_inversion(FunctionHandle_t* instance, bool invert);

/**
 * @brief Get the function's logic type
 * 
 * @param[in]  instance A pointer to the struct containing the function's data
 * @param[out] type A pointer to the variable that stores the function's logic type
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's logic type was retrieved successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL
 */
int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type);

/**
 * @brief Set the function's logic type
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] type The function type to be set
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's logic type was set successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM The function instance is NULL
 */
int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type);

/**
 * @brief Get the function's input memory address
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input address to be retrived
 * @param[out] p_input A pointer to store the address of the retrieved input channel
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's input address was retrieved successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL or the input number is invalid for the current function type
 */
int32_t function_get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t** p_input);

/**
 * @brief Set the function's input memory address
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input address to be set
 * @param[in] p_input A pointer with the address of the input channel
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's input address was set successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL or the input number is invalid for the current function type
 */
int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input);

/**
 * @brief Get the function's input edge type
 * 
 * @param[in]  instance A pointer to the struct containing the function's data
 * @param[in]  input_nbr The number of the input edge type to be retrieved
 * @param[out] p_input A pointer to store the retrieved input edge type
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's input edge type was retrieved successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL or the input number is invalid for the current function type
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The current function type can't have input edges configured
 */
int32_t function_get_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t* p_edge);

/**
 * @brief Set the function's input edge type
 * 
 * @param[in] instance A pointer to the struct containing the function's data
 * @param[in] input_nbr The number of the input edge type to be set
 * @param[in] p_input The input edge type to be set
 * 
 * @return An error code if negative
 * @retval LIB_PDM_ERROR_NONE The function's input edge type was set successfully
 * @retval LIB_PDM_ERROR_WRONG_PARAM Any parameter is NULL or the input number is invalid for the current function type
 * @retval LIB_PDM_ERROR_FUNCTION_TYPE The current function type can't have input edges configured
 */
int32_t function_set_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t edge);

#endif  // LIB_FUNCTIONS_FUNCTIONS_H_
