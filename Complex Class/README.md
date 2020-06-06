# Complex Class

A simple , well-commented example on how to bind C++ classes to JavaScript Code.

Make sure you have `node` installed on your device.

To execute the script, fireup a terminal and run `node test.js`.

You can also compile the C++ source file into a WebAssembly Module (WASM) manually, but you will need to have the EMCC compiler installed.

To manually compile, run the following command in your terminal:

``` emcc --bind -o Complex.js Complex.cpp -s MODULARIZE=1 ```

**(The following section has been crossed out temporarily due to several issues)**

~~Place all files in your `htdocs` folder.~~

~~You might also compile the `wasm` module manually using the following command from CLI:~~

~~```emcc --bind -o Complex.js Complex.cpp -s EXPORTED_FUNCTIONS="['_main']"```~~
