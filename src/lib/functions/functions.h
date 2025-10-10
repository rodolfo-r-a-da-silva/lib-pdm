#ifndef LIB_FUNCTIONS_FUNCTIONS_H_
#define LIB_FUNCTIONS_FUNCTIONS_H_

#include <stdbool.h>
#include <stdint.h>

#include "common/pdm_errno.h"

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

typedef struct {
    int32_t output;
    FunctionType_t type;
    bool is_init;
} FunctionHandle_t;

int32_t function_init(FunctionHandle_t* instance);
int32_t function_deinit(FunctionHandle_t* instance);
bool function_is_init(FunctionHandle_t* instance);
int32_t function_get_result(FunctionHandle_t* instance, int32_t* result);
int32_t function_get_type(FunctionHandle_t* instance, FunctionType_t* type);
int32_t function_set_type(FunctionHandle_t* instance, FunctionType_t type);

#endif  // LIB_FUNCTIONS_FUNCTIONS_H_
