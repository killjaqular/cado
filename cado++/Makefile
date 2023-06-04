COMPILER_FLAGS = -Wall -Werror -Wextra -Wpedantic\
				 -fsanitize=address -fsanitize=undefined -fsanitize=leak\
				 -std=c++20

all: Cado

build:
	mkdir -p build

Cado: build
	g++ $(COMPILER_FLAGS) src/main.cpp -o build/Cado

clean:
	rm build/*
