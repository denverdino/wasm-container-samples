FROM rust:1.41 AS builder
RUN rustup target add wasm32-wasi
COPY . /demo
WORKDIR /demo
RUN cargo build --target wasm32-wasi

FROM scratch
COPY --from=builder /demo/target/wasm32-wasi/debug/demo.wasm .
COPY README.md .
ENTRYPOINT ["demo.wasm", "README.md", "README.md.out"]