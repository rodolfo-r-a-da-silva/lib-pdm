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
- [ ] Initialization Can get the initialized state to true
- [ ] Denitialization Can get the initialized state to false
- [ ] Initialization Can get output to zero
- [ ] Denitialization Can get output to zero
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
    - [x] "0" input results in true - test_whenNotFunctionInputIsFalse_thenResultIsTrue
    - [x] "1" input results in false - test_whenNotFunctionInputIsTrue_thenResultIsFalse

### "AND" function tests
- [ ] Initialization with correct parameters
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
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
    - [ ] Can't run when not initialized
    - [ ] Can run when initialized
- [ ] Function logic
    - [ ] Two "0" inputs results in true
    - [ ] One "0" and one "1" input results in false
    - [ ] Two "1" inputs results in true

### "OR" function tests
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
    - [ ] Single "0" input results in false
    - [ ] One "0" and one "1" input results in true
    - [ ] Two "1" inputs results in true

### "XOR" function tests
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
    - [ ] Two "0" inputs result in false
    - [ ] One "0" and one "1" input results in true
    - [ ] Two "1" inputs results in false

### "Bitwise AND" function tests
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

### "Equals to" functions tests
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
    - [ ] Input 0 greater than input 1 results in false
    - [ ] Input 0 equals to input 1 results in true

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
