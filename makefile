CC =g++
CFLAGS =-Wall -Wextra -ggdb

main: src/main.cpp
	$(CC) $(CFLAGS) -o bin/main src/main.cpp
