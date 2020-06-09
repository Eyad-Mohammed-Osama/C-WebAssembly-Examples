const Module = require("./Functions");
const WASM = Module({
    wasmBinaryFile : "./Functions.wasm"
});

WASM.then((res) => {
    //  The following lines are just shortcuts to the full syntax
    //  So instead of writing res.Add() it's enough to call Add()
    const Add           = res.Add;
    const PrintString   = res.PrintString;
    const PrintInteger  = res.PrintInteger;
    const ArraySum      = res.ArraySum;
    const I32Vector     = res.I32Vector;

    let x = 3;
    let y = 4;
    console.log(x + " + " + y + " = " + Add(x, y)); // Trying the Add() functions
    
    PrintString("This is a string");    //  Trying the PrintString() function
    PrintInteger(472);                  //  Trying the PrintInteger() function

    //  std::vector<int> is exposed to JS under the name I32Vector()
    //  This also expose C++ std::vector APIs to JS
    const vector = new I32Vector();     
    const arr = [2, 4, 7, 11, 13, 16, 19];
    for (let i = 0; i < arr.length; i++) {
        vector.push_back(arr[i]);   //  The push_back() method from C++
    }
    
    //  In C++, operator overloading allows us to overload the usage of [] operator
    //  In JS, operator overloading isn't supported, therefore we use the get() method instead
    for (let i = 0; i < vector.size(); i++) {
        console.log(vector.get(i));
    }

    console.log("The sum of array elements is: " + ArraySum(vector));   // Call ArraySum() method
});