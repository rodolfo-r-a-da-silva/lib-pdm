#ifndef LIB_FUNCTIONS_FUNCTIONS_H_
#define LIB_FUNCTIONS_FUNCTIONS_H_

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t FunctionInstance_t;

typedef enum {
    kFunctionTypeNone = 0U,
    kFunctionTypeAND,
    kFunctionTypeOR,

    kFunctionTypeMax
} FunctionType_t;

typedef enum {
    kFunctionInputEdgeNone = 0U,
    kFunctionInputEdgeFalling,
    kFunctionInputEdgeRising,
    kFunctionInputEdgeBoth,

    kFunctionInputEdgeMax
} FunctionInputEdge_t;

int32_t function_init(FunctionInstance_t instance);
int32_t function_deinit(FunctionInstance_t instance);
int32_t function_get_result(FunctionInstance_t instance, int32_t* result);
int32_t function_get_type(FunctionInstance_t instance, FunctionType_t* type);
int32_t function_set_type(FunctionInstance_t instance, FunctionType_t type);

#endif  // LIB_FUNCTIONS_FUNCTIONS_H_
