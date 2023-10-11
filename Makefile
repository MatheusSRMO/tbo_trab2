all:
	gcc -o main main.c src/**/*.c -g -Iinclude -Isrc -Wall -Wextra -Werror -Wpedantic -std=c99 -lm
clean:
	rm -f main
