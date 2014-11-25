SRC_FILES=main.c mapgen.c print.c player.c input.c
CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c99 -g
LFLAGS = -lncurses

all: main

main: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $(SRC_FILES) $(LFLAGS)

clean:
	rm -f main
