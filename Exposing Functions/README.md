# Exposing Functions

A simple , well-commented example on how to expose C++ functions to JavaScript Code.

Make sure you have `node` installed on your device.

To execute the script, fireup a terminal and run `node test.js`.

You can also compile the C++ source file into a WebAssembly Module (WASM) manually, but you will need to have the EMCC compiler installed.

To manually compile, run the following command in your terminal:

``` emcc --bind -o Functions.js Functions.cpp -s MODULARIZE=1 ```

