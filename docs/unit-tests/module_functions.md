### General tests
- [ ] Function instance argument is NULL
    - [ ] Init returns wrong param error
    - [ ] Deinit returns wrong param error
    - [ ] Is init returns false
    - [x] Set type returns wrong param error - test_whenSetTypeWithNullInstance_thenReturnWrontParamError
    - [x] Get type returns wrong param error - test_whenGetTypeWithNullInstance_thenReturnWrontParamError
    - [ ] Set input returns wrong param error
    - [ ] Get input returns wrong param error
    - [ ] Get result inversion returns wrong param error
    - [ ] Get result returns wrong param error
    - [ ] Run returns wrong param error

- [ ] Secondary pointer is NULL
    - [x] Get type returns wrong param error - test_whenGetTypeWithNullType_thenReturnWrongParamError
    - [ ] Set input returns wrong param error
    - [ ] Get input returns wrong param error
    - [ ] Get result returns wrong param error

- [x] Can set and get the instance's function type - test_whenSetAndGetType_thenReturnsNoErrorWhenNotInit
- [ ] Can't change function type when initialized
- [ ] Function type is not changed on initialization
- [ ] Function type is not changed on on deinitialization
- [ ] Initialization sets the initialized state to true
- [ ] Denitialization sets the initialized state to false
- [ ] Initialization sets output to zero
- [ ] Denitialization sets output to zero
- [x] "is_init" function returns false when not initialized - test_whenNotInitialized_thenIsInitReturnsFalse
- [x] "is_init" function returns true when not initialized - test_whenInitialized_thenIsInitReturnsTrue

### Boolean from integers
- [ ] 0 is false
- [ ] 1 is true
- [ ] -1 is true

### Debounced output tests

### "None" function tests
- [x] Can't set inputs - test_whenNoneFunctionSetInput0_thenReturnWrongParamError
- [x] Can't get inputs - test_whenNoneFunctionGetInput0_thenReturnWrongParamError
- [x] Can't set input edges - test_whenNoneFunctionSetInput0Edge_thenReturnWrongParamError
- [x] Can't get input edges - test_whenNoneFunctionGetInput0Edge_thenReturnWrongParamError
- [x] Can't set inverted result logic - test_whenNoneFunctionSetInvertedResult_thenReturnFunctionTypeError
- [x] Can't get inverted result logic - test_whenNoneFunctionGetInvertedResult_thenReturnFunctionTypeError
- [x] Can't initialize - test_whenNoneFunctionInit_thenReturnTypeError
- [x] Can't deinitialize - test_whenNoneFunctionDeinit_thenReturnTypeError
- [x] Can't run - test_whenNoneFunctionRun_thenReturnTypeError

### "NOT" function tests
- [x] Initialization with correct parameters
    - [x] Can't set input 1 or higher - test_whenNotFunctionSetInput1_thenReturnsWrongParamError
    - [x] Can set input 0 - test_whenNotSetFunctionInput0_thenReturnsNoError
    - [x] Can't get input 1 or higher - test_whenNotFunctionGetInput1_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenNotFunctionGetInput0_thenReturnNoError
    - [x] Can get a set input - test_whenNotFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenNotFunctionSetInput0Edge_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenNotFunctionGetInput0Edge_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenNotFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenNotFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without inputs - test_whenNotFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can initialize with one input - test_whenNotFunctionInitWithInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenNotFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenNotFunctionRun_thenReturnNoError
- [x] Function logic
    - [x] "0" input results in true - test_whenNotFunctionInputIs0_thenResultIsTrue
    - [x] "1" input results in false - test_whenNotFunctionInputIs1_thenResultIsFalse
    - [x] "2" input results in false - test_whenNotFunctionInputIs2_thenResultIsFalse
    - [x] "-1" input results in false - test_whenNotFunctionInputIsMinus1_thenResultIsFalse

### "AND" function tests
- [x] Initialization with correct parameters
    - [x] Can't set input 2 or higher - test_whenAndFunctionSetInput2_thenReturnWrongParamError
    - [x] Can set input 0 - test_whenAndFunctionSetInput0_thenReturnNoError
    - [x] Can set input 1 - test_whenAndFunctionSetInput1_thenReturnNoError
    - [x] Can't get input 2 or higher - test_whenAndFunctionGetInput2_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenAndFunctionGetInput0_thenReturnNoError
    - [x] Can get input 1 - test_whenAndFunctionGetInput1_thenReturnNoError
    - [x] Can get a set input - test_whenAndFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenAndFunctionSetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenAndFunctionGetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenAndFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenAndFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without input 0 - test_whenAndFunctionInitWithoutInput0_thenReturnInputError
    - [x] Can't initialize without input 1 - test_whenAndFunctionInitWithoutInput1_thenReturnInputError
    - [x] Can initialize with two inputs - test_whenAndFunctionInitWithBothInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenAndFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenAndFunctionRun_thenReturnNoError
- [x] Function logic
    - [x] Input 0 and 1 are "0" results in false - test_whenAndFunctionInput0And1Are0_thenResultIsFalse
    - [x] Input 0 is "0" and 1 is "1" results in false - test_whenAndFunctionInput0Is0And1Is1_thenResultIsFalse
    - [x] Input 0 is "1" and 1 is "0" results in false - test_whenAndFunctionInput0Is1And1Is0_thenResultIsFalse
    - [x] Input 0 and 1 are "1" results in true - test_whenAndFunctionInput0And1Are1_thenResultIsTrue
    - [x] Input 0 is "1" and 1 is "2" results in true - test_whenAndFunctionInput0Is1And1Is2_thenResultIsTrue
    - [x] Input 0 is "1" and 1 is "-1" results in true - test_whenAndFunctionInput0Is1And1IsMinus1_thenResultIsTrue

### "OR" function tests
- [x] Initialization with correct parameters
    - [x] Can't set input 2 or higher - test_whenOrFunctionSetInput2_thenReturnWrongParamError
    - [x] Can set input 0 - test_whenOrFunctionSetInput0_thenReturnNoError
    - [x] Can set input 1 - test_whenOrFunctionSetInput1_thenReturnNoError
    - [x] Can't get input 2 or higher - test_whenOrFunctionGetInput2_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenOrFunctionGetInput0_thenReturnNoError
    - [x] Can get input 1 - test_whenOrFunctionGetInput1_thenReturnNoError
    - [x] Can get a set input - test_whenOrFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenOrFunctionSetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenOrFunctionGetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenOrFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenOrFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without inputs - test_whenOrFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can't initialize without input 0 - test_whenOrFunctionInitWithoutInput0_thenReturnInputError
    - [x] Can't initialize without input 1 - test_whenOrFunctionInitWithoutInput1_thenReturnInputError
    - [x] Can initialize with two inputs - test_whenOrFunctionInitWithBothInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenOrFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenOrFunctionRun_thenReturnNoError
- [x] Function logic
    - [x] Input 0 and 1 are "0" results in false - test_whenOrFunctionInput0And1Are0_thenResultIsFalse
    - [x] Input 0 is "0" and 1 is "1" results in true - test_whenOrFunctionInput0Is1And1Is0_thenResultIsTrue
    - [x] Input 0 is "1" and 1 is "0" results in true - test_whenOrFunctionInput0Is0And1Is1_thenResultIsTrue
    - [x] Input 0 and 1 are "1" results in true - test_whenOrFunctionInput0And1Are1_thenResultIsTrue
    - [x] Input 0 is "0" and 1 is "2" results in true - test_whenOrFunctionInput0Is0And1Is2_thenResultIsTrue
    - [x] Input 0 is "0" and 1 is "-1" results in true - test_whenOrFunctionInput0Is0And1IsMinus1_thenResultIsTrue

### "XOR" function tests
- [x] Initialization with correct parameters
    - [x] Can't set input 2 or higher - test_whenXorFunctionSetInput2_thenReturnWrongParamError
    - [x] Can set input 0 - test_whenXorFunctionSetInput0_thenReturnNoError
    - [x] Can set input 1 - test_whenXorFunctionSetInput1_thenReturnNoError
    - [x] Can't get input 2 or higher - test_whenXorFunctionGetInput2_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenXorFunctionGetInput0_thenReturnNoError
    - [x] Can get input 1 - test_whenXorFunctionGetInput1_thenReturnNoError
    - [x] Can get a set input - test_whenXorFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenXorFunctionSetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenXorFunctionGetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenXorFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenXorFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without inputs - test_whenXorFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can't initialize without input 0 - test_whenXorFunctionInitWithoutInput0_thenReturnInputError
    - [x] Can't initialize without input 1 - test_whenXorFunctionInitWithoutInput1_thenReturnInputError
    - [x] Can initialize with two inputs - test_whenXorFunctionInitWithBothInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenXorFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenXorFunctionRun_thenReturnNoError
- [x] Function logic
    - [x] Input 0 and 1 are "0" results in false - test_whenXorFunctionInput0And1Are0_thenResultIsFalse
    - [x] Input 0 is "0" and 1 is "1" results in true - test_whenXorFunctionInput0Is0And1Is1_thenResultIsTrue
    - [x] Input 0 is "1" and 1 is "0" results in true - test_whenXorFunctionInput0Is1And1Is0_thenResultIsTrue
    - [x] Input 0 and 1 are "1" results in false - test_whenXorFunctionInput0And1Are1_thenResultIsFalse
    - [x] Input 0 is "0" and 1 is "2" results in true - test_whenXorFunctionInput0Is0And1Is2_thenResultIsTrue
    - [x] Input 0 is "0" and 1 is "-1" results in true - test_whenXorFunctionInput0Is0And1IsMinus1_thenResultIsTrue
    - [x] Input 0 is "-1" and 1 is "2" results in false - test_whenXorFunctionInput0IsMinus1And2Is2_thenResultIsFalse

### "Mask" function tests
- [x] Initialization with correct parameters
    - [x] Can't set input 2 or higher - test_whenMaskFunctionSetInput2_thenReturnWrongParamError
    - [x] Can set input 0 - test_whenMaskFunctionSetInput0_thenReturnNoError
    - [x] Can set input 1 - test_whenMaskFunctionSetInput1_thenReturnNoError
    - [x] Can't get input 2 or higher - test_whenMaskFunctionGetInput2_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenMaskFunctionGetInput0_thenReturnNoError
    - [x] Can get input 1 - test_whenMaskFunctionGetInput1_thenReturnNoError
    - [x] Can get a set input - test_whenMaskFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenMaskFunctionSetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenMaskFunctionGetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenMaskFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenMaskFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without inputs - test_whenMaskFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can't initialize without input 0 - test_whenMaskFunctionInitWithoutInput0_thenReturnInputError
    - [x] Can't initialize without input 1 - test_whenMaskFunctionInitWithoutInput1_thenReturnInputError
    - [x] Can initialize with two inputs - test_whenMaskFunctionInitWithBothInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenMaskFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenMaskFunctionRun_thenReturnNoError
- [ ] Function logic

### "Equals to" functions tests
- [x] Initialization with correct parameters
    - [x] Can't set input 2 or higher - test_whenEqFunctionSetInput2_thenReturnWrongParamError
    - [x] Can set input 0 - test_whenEqFunctionSetInput0_thenReturnNoError
    - [x] Can set input 1 - test_whenEqFunctionSetInput1_thenReturnNoError
    - [x] Can't get input 2 or higher - test_whenEqFunctionGetInput2_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenEqFunctionGetInput0_thenReturnNoError
    - [x] Can get input 1 - test_whenEqFunctionGetInput1_thenReturnNoError
    - [x] Can get a set input - test_whenEqFunctionSetInput_thenGetInputRetrievesAddress
    - [x] Can't set input edges - test_whenEqFunctionSetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can't get input edges - test_whenEqFunctionGetInpuEdge0_thenReturnFunctionTypeError
    - [x] Can set inverted result logic - test_whenEqFunctionSetInvertedResultWithTrue_thenReturnErrorNone
    - [x] Can get inverted result logic - test_whenEqFunctionGetInvertedResultAfterSetting_thenReturnErrorNoneAndGetInversion
    - [x] Can't initialize without inputs - test_whenEqFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can't initialize without input 0 - test_whenEqFunctionInitWithoutInput0_thenReturnInputError
    - [x] Can't initialize without input 1 - test_whenEqFunctionInitWithoutInput1_thenReturnInputError
    - [x] Can initialize with two inputs - test_whenEqFunctionInitWithBothInputs_thenReturnNoError
    - [x] Can't run when not initialized - test_whenEqFunctionRunWithoutInit_thenReturnInitError
    - [x] Can run when initialized - test_whenEqFunctionRun_thenReturnNoError
- [x] Function logic
    - [x] Input 0 and 1 are "0" results in true - test_whenEqFunctionInput0And1Are0_thenResultIsTrue
    - [x] Input 0 is "0" and 1 is "1" results in false - test_whenEqFunctionInput0Is0And1Is1_thenResultIsFalse
    - [x] Input 0 is "1" and 1 is "0" results in false - test_whenEqFunctionInput0Is1And1Is0_thenResultIsFalse
    - [x] Input 0 and 1 are "1" results in true - test_whenEqFunctionInput0And1Are1_thenResultIsTrue
    - [x] Input 0 is "1" and 1 is "2" results in false - test_whenEqFunctionInput0Is1And1Is2_thenResultIsFalse
    - [x] Input 0 is "1" and 1 is "-1" results in false - test_whenEqFunctionInput0Is1And1IsMinus1_thenResultIsFalse
    - [x] Input 0 and 1 are "2" results in true - test_whenEqFunctionInput0And1Are2_thenResultIsTrue
    - [x] Input 0 and 1 are "-1" results in true - test_whenEqFunctionInput0And1AreMinus1_thenResultIsTrue

### "Less than" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can set input 1
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get input 1
    - [ ] Can get a set input
    - [ ] Can't set input edges
    - [ ] Can't get input edges
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic
    - [ ] Input 0 lesser than input 1 results in true
    - [ ] Input 0 greater than input 1 results in false
    - [ ] Input 0 equals to input 1 results in false

### "More than" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can set input 1
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get input 1
    - [ ] Can get a set input
    - [ ] Can't set input edges
    - [ ] Can't get input edges
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic
    - [ ] Input 0 lesser than input 1 results in false
    - [ ] Input 0 greater than input 1 results in true
    - [ ] Input 0 equals to input 1 results in false

### "Hysteresis" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can't set input edges
    - [ ] Can't get input edges
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can initialize with only one input
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic

### "Blink" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can get a set input
    - [ ] Can't set input edges
    - [ ] Can't get input edges
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can initialize with only one input
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic

### "Pulse" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can get a set input
    - [ ] Can't set input 1 edge or higher
    - [ ] Can set input 0 edge
    - [ ] Can't set "none" as edge
    - [ ] Can't get input 1 edge or higher
    - [ ] Can get input 0 edge
    - [ ] Can get a set input edge
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize without input edge configured
    - [ ] Can initialize with only one input and edge configured
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic

### "Set Reset" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get a set input
    - [ ] Can't set input 2 edge or higher
    - [ ] Can set input 0 edge
    - [ ] Can't set "none" as edge
    - [ ] Can't get input 2 edge or higher
    - [ ] Can get input 0 edge
    - [ ] Can get a set input edge
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic

### "Toggle" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get a set input
    - [ ] Can't set input 2 edge or higher
    - [ ] Can set input 0 edge
    - [ ] Can't set "none" as edge
    - [ ] Can't get input 2 edge or higher
    - [ ] Can get input 0 edge
    - [ ] Can get a set input edge
    - [ ] Can set inverted result logic
    - [ ] Can get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with 2 inputs and edges configured
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic

### "Counter" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 4 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 4 or higher
    - [ ] Can get input 0
    - [ ] Can get a set input
    - [ ] Can't set input 4 edge or higher
    - [ ] Can set input 0 edge
    - [ ] Can't set "none" as edge
    - [ ] Can't get input 4 edge or higher
    - [ ] Can get input 0 edge
    - [ ] Can get a set input edge
    - [ ] Can't set inverted result logic
    - [ ] Can't get inverted result logic
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with four inputs and edges configured
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic
