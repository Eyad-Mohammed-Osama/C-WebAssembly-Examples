#include <iostream>
#include <cmath>
#include <emscripten/bind.h>
using namespace emscripten;

static int count = 0;

class Complex { 
    private:
    double real;
    double imaginary;

    public:
    Complex(double real = 0, double imaginary = 0) {
        this->real = real;
        this->imaginary = imaginary;
        count++;    //  Each instance increase the counter by 1
    }

    Complex Add(Complex c) {
        Complex result = Complex();
        result.real = this->real + c.real;
        result.imaginary = this->imaginary + c.imaginary;
        count--;    //  When creating result object , a false increment happens
        return result;
    }

    Complex Subtract(Complex c) {
        Complex result = Complex();
        result.real = this->real - c.real;
        result.imaginary = this->imaginary - c.imaginary;
        count--;    //  When creating result object , a false increment happens
        return result;
    }

    double Length() const {
        return sqrt(pow(this->real, 2) + pow(this->imaginary, 2));
    }

    void SetReal(double real) {
        this->real = real;
    }

    double GetReal() const {
        return this->real;
    }

    void SetImaginary(double imaginary) {
        this->imaginary = imaginary;
    }

    double GetImaginary() const {
        return this->imaginary;
    }

    ~Complex() {
        count--;    //  Decrease the counter if an object destructor has been called
    }
};

EMSCRIPTEN_BINDINGS(module) {
    class_<Complex>("Complex")                  //  Exporting the class to JS as "Complex"
    .constructor<double, double>()              //  Exporting the constructor , it takes 2 parameters of type double
    .function("Add", &Complex::Add)             //  Exporting the "Add()" method from Complex
    .function("Subtract", &Complex::Subtract)   //  Exporting the "Subtract()" method from Complex
    .property("Length", &Complex::Length)       //  Exporting the "Length()" method from Complex as a read-only property
    .property("Real", &Complex::GetReal, &Complex::SetReal)                 //  Exporting the "GetReal() / SetReal()" methods as a read/write property
    .property("Imaginary", &Complex::GetImaginary, &Complex::SetImaginary)  //  Exporting the "GetImaginary() / SetImaginary()" methods as a read/write property
    .class_property("Count", &count);           //  Exporting the static counter as a read-only property
}

int main() {
    std::cout << "Complex module has been loaded successfully" << std::endl;
    return 0;
}