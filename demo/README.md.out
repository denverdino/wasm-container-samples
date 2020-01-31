# Rust demo

Sample from https://github.com/bytecodealliance/wasmtime/blob/master/docs/WASI-tutorial.md


### Compile

```
$ rustup target add wasm32-wasi
$ cargo build --target wasm32-wasi
```

### Run

```
wasmer run --dir=. target/wasm32-wasi/debug/demo.wasm -- README.md README.md.out
```

