all:
	gcc -o trab2 trab2.c src/**/*.c -g -Iinclude -Isrc -Wall -Wextra -Werror -Wpedantic -std=c99 -lm
clean:
	rm -f trab2
