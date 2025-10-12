- [x] Can set and get the instance's function type - test_GetAndSetType_ReturnsNoErrorWhenNotInit
- [x] Only initialize when type is different from "None"
    - [x] Initializes when type is not "None" - test_InitWhenTypeIsNotNone_ReturnsNoError
    - [x] Does not initialized when type is "None" - test_InitWhenTypeIsNone_ReturnsTypeError
- [x] Function type is not changed on initialization - test_InitDoesNotChangeChangeType
- [x] Function type is not changed on on deinitialization - test_DeinitDoesNotChangeType
- [x] Can only change function type when not initialized - test_ChangeTypeWhenInitialized_ReturnsErrorAndKeepsType
- [x] Initialization sets the initialized state to true - test_InitSetsStateToInitialized
- [x] Denitialization sets the initialized state to false - test_DeinitSetsStateToNotInitialized
- [ ] Initialization sets output to zero
- [ ] Denitialization sets output to zero

### "NOT" function tests
- [ ] Initialization with correct parameters
    - [ ] Initializes with one input
    - [ ] Does not initialize without inputs
- [ ] Function logic
    - [ ] "0" input results in true
    - [ ] "1" input results in false

### "AND" function tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
    - [ ] Initializes with number of inputs from "define"
- [ ] Function logic
    - [ ] One "0" and one "1" input results in false
    - [ ] Two "1" inputs results in true

### "OR" function tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
    - [ ] Initializes with number of inputs from "define"
- [ ] Function logic
    - [ ] Single "0" input results in false
    - [ ] Single "1" input results in true
    - [ ] One "0" and one "1" input results in true
    - [ ] Two "1" inputs results in true

### "XOR" function tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic
    - [ ] Two "0" inputs result in false
    - [ ] One "0" and one "1" input results in true
    - [ ] Two "1" inputs results in false

### "Bitwise AND" function tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic

### "Equals to" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic
    - [ ] Input 1 lesser than input 2 results in false
    - [ ] Input 1 greater than input 2 results in false
    - [ ] Input 1 equals to input 2 results in true

### "Less than" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic
    - [ ] Input 1 lesser than input 2 results in true
    - [ ] Input 1 greater than input 2 results in false
    - [ ] Input 1 equals to input 2 results in false

### "More than" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic
    - [ ] Input 1 lesser than input 2 results in false
    - [ ] Input 1 greater than input 2 results in true
    - [ ] Input 1 equals to input 2 results in false

### "Sum" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic
    - [ ] Result in the sum of input 1 and input 2

### "Hysteresis" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic

### "Blink" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Initializes with only one input
- [ ] Function logic

### "Pulse" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Initializes with only one input
- [ ] Function logic

### "Set" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic

### "Reset" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic

### "Toggle" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with two inputs
- [ ] Function logic

### "Counter" functions tests
- [ ] Initialization with correct parameters
    - [ ] Does not initialize without inputs
    - [ ] Does not initialize with only one input
    - [ ] Initializes with four inputs
- [ ] Function logic
