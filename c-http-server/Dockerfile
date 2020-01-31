FROM trzeci/emscripten:sdk-tag-1.38.43-64bit AS builder
COPY * /src/
RUN make

FROM scratch
COPY --from=builder /src/main.wasm .
CMD ["main.wasm", "3090"]