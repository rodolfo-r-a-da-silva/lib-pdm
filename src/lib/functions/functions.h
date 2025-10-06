#ifndef LIB_FUNCTIONS_FUNCTIONS_H_
#define LIB_FUNCTIONS_FUNCTIONS_H_

#include <stdint.h>

typedef uint32_t FunctionInstance_t;

int32_t function_init(FunctionInstance_t instance);
int32_t function_get_result(FunctionInstance_t instance, int32_t* result);

#endif  // LIB_FUNCTIONS_FUNCTIONS_H_
