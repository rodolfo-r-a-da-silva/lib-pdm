- [x] Can set and get the instance's function type - test_GetAndSetType_ReturnsNoErrorWhenNotInit
- [x] Only initialize when type is different from "None" - test_InitWhenTypeIsNotNone_ReturnsNoError / test_InitWhenTypeIsNone_ReturnsTypeError
- [x] Function type is not changed on initialization - test_InitDoesNotChangeChangeType
- [x] Function type is not changed on on deinitialization - test_DeinitDoesNotChangeType
- [x] Can only change function type when not initialized - test_ChangeTypeWhenInitialized_ReturnsErrorAndKeepsType
- [x] Initialization sets the initialized state to true - test_InitSetsStateToInitialized
- [x] Denitialization sets the initialized state to false - test_DeinitSetsStateToNotInitialized
- [ ] Initialization sets output to zero
- [ ] Denitialization sets output to zero

### "NOT" function tests
- [ ] "0" input results in true
- [ ] "1" input results in false

### "AND" function tests
- [ ] Does not initialize with less than two inputs
- [ ] One "0" and one "1" input results in false
- [ ] Two "1" inputs results in true

### "OR" function tests
- [ ] Does not initialize with less than two inputs
- [ ] Single "0" input results in false
- [ ] Single "1" input results in true
- [ ] One "0" and one "1" input results in true
- [ ] Two "1" inputs results in true

### "XOR" function tests
- [ ] Only initializes with two inputs
- [ ] Two "0" inputs result in false
- [ ] One "0" and one "1" input results in true
- [ ] Two "1" inputs results in false

### "Bitwise AND" function tests
- [ ] Only initializes with two inputs

### "Equals to" functions tests
- [ ] Only initializes with two inputs

### "Less than" functions tests
- [ ] Only initializes with two inputs

### "More than" functions tests
- [ ] Only initializes with two inputs

### "Sum" functions tests
- [ ] Only initializes with two inputs

### "Subtraction" functions tests
- [ ] Only initializes with two inputs

### "Hysteresis" functions tests
- [ ] Only initializes with one input

### "Blink" functions tests
- [ ] Only initializes with one input

### "Pulse" functions tests
- [ ] Only initializes with one input

### "Set" functions tests
- [ ] Only initializes with two inputs

### "Reset" functions tests
- [ ] Only initializes with two inputs

### "Toggle" functions tests
- [ ] Only initializes with two inputs

### "Counter" functions tests
- [ ] Only initializes with six inputs
