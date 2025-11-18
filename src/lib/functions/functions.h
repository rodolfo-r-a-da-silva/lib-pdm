#ifndef LIB_FUNCTIONS_FUNCTIONS_H_
#define LIB_FUNCTIONS_FUNCTIONS_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/pdm_errno.h"

#define LIB_PDM_FUNCTION_FALSE  0
#define LIB_PDM_FUNCTION_TRUE  1

#define LIB_PDM_FUNCTION_NOT_INPUTS  1U
#define LIB_PDM_FUNCTION_AND_INPUTS  2U
#define LIB_PDM_FUNCTION_OR_INPUTS  2U
#define LIB_PDM_FUNCTION_XOR_INPUTS  2U

typedef enum {
    kFunctionTypeNone = 0U,
    kFunctionTypeNOT,
    kFunctionTypeAND,
    kFunctionTypeOR,
    kFunctionTypeXOR,
    kFunctionTypeBitwiseAND,
    kFunctionTypeEquals,
    kFunctionTypeLess,
    kFunctionTypeMore,
    kFunctionTypeSum,
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
    int32_t* input;
    bool invert;
} FunctionDataNOT_t;

typedef struct {
    int32_t* input[LIB_PDM_FUNCTION_AND_INPUTS];
    bool invert;
} FunctionDataAND_t;

typedef struct {
    int32_t* input[LIB_PDM_FUNCTION_OR_INPUTS];
    bool invert;
} FunctionDataOR_t;

typedef struct {
    int32_t* input[LIB_PDM_FUNCTION_XOR_INPUTS];
    bool invert;
} FunctionDataXOR_t;

typedef struct {
    int32_t output;
    FunctionType_t type;
    bool is_init;

    union {
        FunctionDataNOT_t data_not;
        FunctionDataAND_t data_and;
        FunctionDataOR_t data_or;
        FunctionDataOR_t data_xor;
    };
} FunctionHandle_t;

int32_t function_init(FunctionHandle_t* instance);
int32_t function_deinit(FunctionHandle_t* instance);
bool function_is_init(FunctionHandle_t* instance);
int32_t function_run(FunctionHandle_t* instance);
int32_t function_get_result(FunctionHandle_t* instance, int32_t* result);
int32_t function_get_result_invertion(FunctionHandle_t* instance, bool* invert);
int32_t function_set_result_invertion(FunctionHandle_t* instance, bool invert);
int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type);
int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type);
int32_t function_get_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t** p_input);
int32_t function_set_input(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, int32_t* p_input);
int32_t function_get_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t* p_edge);
int32_t function_set_input_edge(FunctionHandle_t* instance, FunctionInputNbr_t input_nbr, FunctionInputEdge_t edge);

#endif  // LIB_FUNCTIONS_FUNCTIONS_H_
