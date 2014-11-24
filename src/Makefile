SRC_FILES=main.c
CC = gcc
CFLAGS = -pedantic -Wall -Wextra -g

all: main

main: $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $(SRC_FILES)

clean:
	rm -f main
