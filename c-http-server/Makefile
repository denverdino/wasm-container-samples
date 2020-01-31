CC=gcc

all: emscripten
	$(CC) -Wall -Werror -o main main.c
	strip main

emscripten:
	emcc -Wall -Werror -o main.js main.c
