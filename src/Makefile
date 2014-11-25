SRC_FILES=main.c mapgen.c print.c
CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c99 -g

all: main

main: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $(SRC_FILES)

clean:
	rm -f main
