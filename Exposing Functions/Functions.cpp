#include <iostream>
#include <vector>
#include <emscripten/bind.h>
using namespace emscripten;

// A function to sum up 2 integers
int Add(int x, int y) {
    return x + y;
}

// A function to print an integer to the console
void Print(int x) {
    std::cout << "The value of (x) is: " << x << std::endl;
}

// A function to print a string to the console
void Print(std::string str) {
    std::cout << "The value of (str) is: " << str << std::endl;
}

// A function to sum elements of a vector that contains signed 32-bit integers
int ArraySum(std::vector<int> numbers) {
    int s = 0;
    for (int i = 0; i < numbers.size(); i++) {
        s = s + numbers[i];
    }
    return s;
}

EMSCRIPTEN_BINDINGS(module) {
    function("Add", &Add);      // The simplest form of exposure

    //  JS Doesn't support function overloading, so if you choose to 
    //  expose an overloaded function from C++ code, you have to choose different names
    //  Otherwise, if you choose to use the same name, the only last exposed copy of the 
    //  function will be used

    //  Expose the function "Print" which returns "void" and has a single parameter of type "int"
    //  Under the name "PrintInteger" to JS
    function<void, int>("PrintInteger", &Print);        

    //  Expose the function "Print" which returns "void" and has a single parameter of type "string"
    //  Under the name "PrintString" to JS
    function<void, std::string>("PrintString", &Print);
    
    //  Expose the function "ArraySum" which accepts a parameter of type std::vector<int>
    //  And returns the sum as a signed 32-bit integer
    function<int, std::vector<int>>("ArraySum", &ArraySum);

    //  Expose the type std::vector<int> to JS under the name "I32Vector"
    register_vector<int>("I32Vector");
}