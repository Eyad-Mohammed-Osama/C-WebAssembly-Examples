## Complex Class
A simple , well-commented example on how to bind C++ classes to JavaScript Code.

Place all files in your `htdocs` folder.

You might also compile the `wasm` module manually using the following command from CLI:

```emcc --bind -o Complex.js Complex.cpp -s EXPORTED_FUNCTIONS="['_main']"```
