### General tests
- [ ] Function instance argument is NULL
    - [ ] Init returns wrong param error
    - [ ] Deinit returns wrong param error
    - [x] Set type returns wrong param error - test_whenSetTypeWithNullInstance_thenReturnWrontParamError
    - [x] Get type returns wrong param error - test_whenGetTypeWithNullInstance_thenReturnWrontParamError
    - [ ] Set input returns wrong param error
    - [ ] Get input returns wrong param error
    - [ ] Get result returns wrong param error
    - [ ] Run returns wrong param error

- [x] Get type with type as NULL pointer returns wrong param error - test_whenGetTypeWithNullType_thenReturnWrongParamError

- [ ] Input pointer is NULL
    - [ ] Set input returns wrong param error
    - [ ] Get input returns wrong param error

- [x] Can set and get the instance's function type - test_whenSetAndGetType_thenReturnsNoErrorWhenNotInit
- [ ] Can't change function type when initialized
- [ ] Function type is not changed on initialization
- [ ] Function type is not changed on on deinitialization
- [ ] Initialization Can get the initialized state to true
- [ ] Denitialization Can get the initialized state to false
- [ ] Initialization Can get output to zero
- [ ] Denitialization Can get output to zero

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
- [x] Can't initialize - test_whenNoneFunctionInit_thenReturnTypeError
- [x] Can't deinitialize - test_whenNoneFunctionDeinit_thenReturnTypeError
- [x] Can't run - test_whenNoneFunctionRun_thenReturnTypeError

### "NOT" function tests
- [ ] Initialization with correct parameters
    - [x] Can't set input 1 or higher - test_whenNotFunctionSetInput1_thenReturnsWrongParamError
    - [x] Can set input 0 - test_whenNotSetFunctionInput0_thenReturnsNoError
    - [x] Can't get input 1 or higher - test_whenNotFunctionGetInput1_thenReturnWrongParamError
    - [x] Can get input 0 - test_whenNotFunctionGetInput0_thenReturnNoError
    - [x] Can get a set function's input
    - [x] Can't initialize without inputs - test_whenNotFunctionInitWithoutInputs_thenReturnInputError
    - [x] Can initialize with one input - test_whenNotFunctionInitWithInputs_thenReturnNoError
- [ ] Function logic
    - [ ] "0" input results in true
    - [ ] "1" input results in false

### "AND" function tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can't set input 0
    - [ ] Can't set input 1
    - [ ] Can't get input 2 or higher
    - [ ] Can't get input 0
    - [ ] Can't get input 1
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
- [ ] Function logic
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
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
- [ ] Function logic
    - [ ] Single "0" input results in false
    - [ ] Single "1" input results in true
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
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
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
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
- [ ] Function logic

### "Equals to" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can set input 1
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get input 1
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
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
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
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
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
- [ ] Function logic
    - [ ] Input 0 lesser than input 1 results in false
    - [ ] Input 0 greater than input 1 results in true
    - [ ] Input 0 equals to input 1 results in false

### "Sum" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 2 or higher
    - [ ] Can set input 0
    - [ ] Can set input 1
    - [ ] Can't get input 2 or higher
    - [ ] Can get input 0
    - [ ] Can get input 1
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can initialize with two inputs
- [ ] Function logic
    - [ ] Result is the sum of input 1 and input 2

### "Hysteresis" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can't initialize without inputs
    - [ ] Can initialize with only one input
- [ ] Function logic

### "Blink" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize without input edge configured
    - [ ] Can initialize with only one input and edge configured
- [ ] Function logic

### "Pulse" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't set input 1 or higher
    - [ ] Can set input 0
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize without input edge configured
    - [ ] Can initialize with only one input and edge configured
- [ ] Function logic

### "Set" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Reset" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Toggle" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Counter" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can get a set function's input
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with four inputs and edges configured
- [ ] Function logic
