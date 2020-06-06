const Module = require("./Complex");
const WASM = Module({
    wasmBinaryFile: "./Complex.wasm"
});

WASM.then((res) => {
    const Complex = res.Complex;

    const c1 = new Complex(3, 4);
    const c2 = new Complex(6, 8);
    const c3 = c1.Add(c2);
    console.log(c1.ToString() + " + " + c2.ToString() + " = " + c3.ToString());
});