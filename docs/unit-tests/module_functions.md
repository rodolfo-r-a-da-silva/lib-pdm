- [ ] When function instance argument is NULL
    - [ ] Init returns wrong param error
    - [ ] Deinit returns wrong param error
    - [ ] Get type returns wrong param error
    - [ ] Set type returns wrong param error
    - [ ] Get input returns wrong param error
    - [ ] Set input returns wrong param error
    - [ ] Get result returns wrong param error
    - [ ] Run  returns wrong param error

- [x] Can set and get the instance's function type - test_whenSetAndGetType_thenReturnsNoErrorWhenNotInit
- [ ] Only initialize when type is different from "None"
    - [ ] Initializes when type is not "None"
    - [ ] Can't initialized when type is "None"
- [ ] Function type is not changed on initialization
- [ ] Function type is not changed on on deinitialization
- [ ] Can only change function type when not initialized
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
- [ ] Can't set inputs
- [ ] Can't get inputs
- [ ] Can't set input edges
- [ ] Can't get input edges
- [ ] Can't initialize
- [ ] Can't deinitialize
- [ ] Can't run

### "NOT" function tests
- [ ] Initialization with correct parameters
    - [x] Can't set input 1 or higher - test_whenSetNotFunctionInput1_thenReturnsWrongParamError
    - [x] Can set input 0 - test_whenSetNotFunctionInput0_thenReturnsNoError
    - [ ] Can't get input 1 or higher
    - [ ] Can get input 0
    - [ ] Can't initialize without inputs
    - [ ] Can initialize with one input
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
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize without input edge configured
    - [ ] Can initialize with only one input and edge configured
- [ ] Function logic

### "Set" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Reset" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Toggle" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with two inputs and edges configured
- [ ] Function logic

### "Counter" functions tests
- [ ] Initialization with correct parameters
    - [ ] Can't initialize without inputs
    - [ ] Can't initialize with only one input
    - [ ] Can't initialize without input edges configured
    - [ ] Can initialize with four inputs and edges configured
- [ ] Function logic
